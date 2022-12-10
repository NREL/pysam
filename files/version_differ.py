from PySAM.PySSC import PySSC
import PySAM.version as old_version
import requests
from collections import OrderedDict
from collections.abc import Iterable
import tempfile
import os
import json
import tarfile
from version import __version__

if old_version.__version__ == __version__:
    raise RuntimeError("Script needs to be run with old release installed and new release's ssc lib under files")

doc_str = "" \
          "This page compares the PySAM Modules' input variables and the defaults for these input variables \n" \
          "between the current release and the last release.\n\nThis helps track which variables " \
          "and defaults have changed between releases to make it easier to notify users during version upgrade.\n\n" \
          "Below are lists for each PySAM Module:\n" \
          "    1. New Default configurations\n" \
          "    2. Removed Default configurations\n" \
          "    3. Modified Variables: New variables, Removed variables and Type-changed variables\n" \
          "    4. Modified Default Values"


########################################################################################
#
# Download the SAM repo tagged for the previous PySAM Release to compare defaults
#
########################################################################################

previous_release = 0
resp = requests.get("https://api.github.com/repos/NREL/pysam/releases").json()
old_release = resp[previous_release]['name']
sam_resp = requests.get("https://api.github.com/repos/NREL/sam/tags").json()
for r in sam_resp:
    if r['name'] == old_release.lower().replace(' ', '-'):
        old_release = r['tarball_url']
        break
print(
    f"Comparing Current branch's SSC Variables with Release `{resp[previous_release]['name']}` published at "
    f"{resp[previous_release]['created_at']}")

tmpdir = tempfile.TemporaryDirectory()
print(f'Using temporary dir {tmpdir.name}')
with requests.get(old_release, stream=True) as File:
    # stream = true is required by the iter_content below
    sam_old_file = os.path.join(tmpdir.name, "pysam_old")
    with open(sam_old_file, 'wb') as fd:
        for chunk in File.iter_content(chunk_size=128):
            fd.write(chunk)

with tarfile.open(sam_old_file, "r:gz") as tf:
    tf.extractall(tmpdir.name)
    # To save the extracted file in directory of choice with same name as downloaded file.
    file_list_old = []
    for tarinfo in tf:
        if "defaults" in tarinfo.name and os.path.splitext(tarinfo.name)[1] == '.json':
            file_list_old.append(tarinfo.name)

sam_path = os.environ.get('SAMNTDIR')
api_path = os.path.join(sam_path, "api", "api_autogen", "library", "defaults")
file_list_new = []

for root, dirs, files in os.walk(api_path):
    for file in files:
        file_list_new.append(root + os.sep + file)

outfile_dict = {}

########################################################################################
#
# Get changed default files
#
########################################################################################

defaults_new = set([os.path.splitext(os.path.basename(i))[0] for i in file_list_new])
defaults_old = set([os.path.splitext(os.path.basename(i))[0] for i in file_list_old])

newly_added_defaults_dict = {}
for n in defaults_new - defaults_old:
    cmod, config = n.split('_')
    if cmod not in newly_added_defaults_dict.keys():
        newly_added_defaults_dict[cmod] = []
    newly_added_defaults_dict[cmod].append(config)
for k, v in newly_added_defaults_dict.items():
    v.sort()
outfile_dict["Cmods with new defaults files"] = newly_added_defaults_dict

newly_removed_defaults_dict = {}
for n in defaults_old - defaults_new:
    cmod, config = n.split('_')
    if cmod not in newly_removed_defaults_dict.keys():
        newly_removed_defaults_dict[cmod] = []
    newly_removed_defaults_dict[cmod].append(config)
for k, v in newly_removed_defaults_dict.items():
    v.sort()
newly_removed_defaults_dict.keys()

outfile_dict["Cmods with removed defaults files"] = newly_removed_defaults_dict


def get_flat_dict(defaults_json):
    output = {}
    for k, v in defaults_json.items():
        if type(v) is dict:
            output.update(get_flat_dict(v))
        else:
            if isinstance(v, Iterable):
                if min(v) == 0 and max(v) == 0:
                    v = [0]
            output[k] = v
    return output


def file_to_flat_dict(filename):
    with open(filename, 'r') as f:
        defaults_json = json.load(f)
        return get_flat_dict(defaults_json)


new_defaults_data = {}
for f in file_list_new:
    file_name = os.path.split(f)[1]
    new_defaults_data[file_name] = file_to_flat_dict(f)

old_defaults_data = {}
for f in file_list_old:
    f = os.path.join(tmpdir.name, f)
    file_name = os.path.split(f)[1]
    old_defaults_data[file_name] = file_to_flat_dict(f)

outfile_dict["Configs with modified defaults"] = {}

for k, new_data in new_defaults_data.items():
    if k in old_defaults_data:
        name = k.split('_')[0]
        config_name = k.split('.')[0]
        old_data = old_defaults_data[k]

        # First, compare sets
        new_key_set = set(new_data.keys())
        old_key_set = set(old_data.keys())

        all_keys = new_key_set.intersection(old_key_set)
        changed_keys = {}
        for key in all_keys:
            v_new = new_data[key]
            v_old = old_data[key]

            if v_new != v_old:
                if isinstance(v_new, Iterable) and isinstance(v_old, Iterable):
                    if len(v_new) + len(v_old) >= 8760 * 2:
                        changed_keys[key] = [">=8760 truncated to 0 index", v_new[0], v_old[0]]
                    else:
                        changed_keys[key] = [v_old, v_new]
                else:
                    changed_keys[key] = [v_old, v_new]
        if len(changed_keys) > 0:
            if name not in outfile_dict["Configs with modified defaults"].keys():
                outfile_dict["Configs with modified defaults"][config_name] = {}
            outfile_dict["Configs with modified defaults"][config_name]['Changed variables'] = changed_keys

# Organize

doc_dict = OrderedDict()
cmods = set(outfile_dict['Cmods with new defaults files'].keys())
cmods = cmods.union(set(outfile_dict['Cmods with removed defaults files'].keys()))
cmods = list(cmods)
cmods.sort()

for c in cmods:
    doc_dict[c] = {}
    if c in outfile_dict['Cmods with new defaults files'].keys():
        doc_dict[c]['new_defaults'] = outfile_dict['Cmods with new defaults files'][c]
    if c in outfile_dict['Cmods with removed defaults files'].keys():
        doc_dict[c]['del_defaults'] = outfile_dict['Cmods with removed defaults files'][c]
    def_dict = {}
    for k, v in outfile_dict['Configs with modified defaults'].items():
        if c in k:
            def_dict[k] = v['Changed variables']
    if len(def_dict) > 0:
        doc_dict[c]['mod_defaults'] = def_dict
    if len(doc_dict[c]) == 0:
        doc_dict.pop(c)

########################################################################################
#
# Get variable changes using PySSC to query Modules' interfaces
#
########################################################################################


def get_var_dict():
    cmod_variables = {}
    i = 0
    while ssc.module_entry(i):
        name = ssc.entry_name(ssc.module_entry(i))
        mod = ssc.module_create(name)
        j = 0
        cmod_variables[name.decode("utf-8")] = {}
        while ssc.module_var_info(mod, j):
            var = ssc.module_var_info(mod, j)
            vname = ssc.info_name(var).decode("utf-8")
            vtype = ssc.info_var_type(var)
            if vtype == 1 or vtype == 3:
                cmod_variables[name.decode("utf-8")][vname] = ssc.info_data_type(var)
            j += 1
        i += 1
    return cmod_variables


new_ssc = os.path.join(os.environ.get("PYSAMDIR"), "files", "libssc.so")
ssc = PySSC(new_ssc)

new_cmod_variables = get_var_dict()

# get old release
previous_release = 0
resp = requests.get("https://api.github.com/repos/NREL/pysam/releases").json()
old_release = resp[previous_release]['tarball_url']

with requests.get(old_release, stream=True) as File:
    # stream = true is required by the iter_content below
    sam_old_file = os.path.join(tmpdir.name, "pysam_old")
    with open(sam_old_file, 'wb') as fd:
        for chunk in File.iter_content(chunk_size=128):
            fd.write(chunk)

old_ssc = ""
with tarfile.open(sam_old_file, "r:gz") as tf:
    tf.extractall(tmpdir.name)
    # To save the extracted file in directory of choice with same name as downloaded file.
    file_list_old = []
    for tarinfo in tf:
        if "libssc" in tarinfo.name:
            old_ssc = tarinfo.name

ssc = PySSC()

old_cmod_variables = get_var_dict()

cmod_int = set(new_cmod_variables.keys()).intersection(set(old_cmod_variables.keys()))


for name in cmod_int:
    pysam_name = "".join([s.capitalize() for s in name.split('_')])
    mod_variables = dict()

    new_key_set = set(new_cmod_variables[name].keys())
    old_key_set = set(old_cmod_variables[name].keys())

    addtl_keys = new_key_set.difference(old_key_set)

    if len(addtl_keys) > 0:
        addtl_keys = list(addtl_keys)
        addtl_keys.sort()
        mod_variables['Added variables'] = addtl_keys

    removed_keys = old_key_set.difference(new_key_set)

    if len(removed_keys) > 0:
        removed_keys = list(removed_keys)
        removed_keys.sort()
        mod_variables['Removed variables'] = removed_keys

    all_keys = new_key_set.intersection(old_key_set)
    changed_keys = {}
    for key in all_keys:
        v_new = new_cmod_variables[name][key]
        v_old = old_cmod_variables[name][key]

        if v_new != v_old:
            if 'Type changed' not in mod_variables.keys():
                mod_variables['Type changed'] = []
            mod_variables['Type changed'].append(key)
    if 'Type changed' in mod_variables.keys():
        mod_variables['Type changed'].sort()
    if len(mod_variables) > 0:
        if pysam_name not in doc_dict.keys():
            doc_dict[pysam_name] = {'mod_variables': mod_variables}
        else:
            doc_dict[pysam_name].update({'mod_variables': mod_variables})

doc_dict = OrderedDict(sorted(doc_dict.items()))

########################################################################################
#
# Print Out VersionChanges.rst
#
########################################################################################

pysam_dir = os.environ.get("PYSAMDIR")

with open(os.path.join(pysam_dir, "docs", "version_changes", __version__ + ".rst"), "w") as f:
    f.write(f'.. {__version__}:\n\n')
    f.write(f'Version {__version__}\n')
    f.write('===============================================\n\n')
    f.write(f'{doc_str}\n\n')
    for cmod, changes in doc_dict.items():
        f.write(cmod + "\n")
        f.write('************************************************\n\n')
        if 'mod_variables' in changes.keys():
            f.write(f':doc:`../modules/{cmod}` Modified Input Variables:\n\n')
            if 'Added variables' in changes['mod_variables']:
                f.write('    New variables:\n\n')
                for v in changes['mod_variables']['Added variables']:
                    f.write(f"         - {v}\n")
                f.write('\n')
            if 'Removed variables' in changes['mod_variables']:
                f.write('    Removed variables:\n\n')
                for v in changes['mod_variables']['Removed variables']:
                    f.write(f"         - {v}\n")
                f.write('\n')
            if 'Type changed' in changes['mod_variables']:
                f.write('    Type-changed variables:\n\n')
                for v in changes['mod_variables']['Type changed']:
                    f.write(f"         - {v}\n")
                f.write('\n')
        if 'new_defaults' in changes.keys():
            f.write(f':doc:`../modules/{cmod}` New Default files:\n\n')
            for v in changes['new_defaults']:
                f.write(f"     - {v}\n")
            f.write("\n")
        if 'del_defaults' in changes.keys():
            f.write(f':doc:`../modules/{cmod}` Removed Default files\n\n')
            for v in changes['del_defaults']:
                f.write(f"     - {v}\n")
            f.write("\n")
        if 'mod_defaults' in changes.keys():
            f.write(f':doc:`../modules/{cmod}` Modified Default Values:\n\n')
            for k, v in changes['mod_defaults'].items():
                f.write(f"     - {k}\n\n        {list(v.keys())}\n\n")
            f.write("\n")
        f.write('\n')
