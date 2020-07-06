from setuptools import setup
import os
import shutil
from files.version import __version__

latest_version = __version__

# prepare package description
from os import path, listdir
pysamdir = os.environ['PYSAMDIR']
os.chdir(pysamdir)
with open(path.join(pysamdir, 'RELEASE.md'), encoding='utf-8') as f:
    long_description = f.read()

# stubs/stubs folder gets emptied during creation of stub files, so need to add these two files back in
open(path.join(pysamdir, "stubs", 'stubs', '__init__.py'), 'w').close()
shutil.copyfile(path.join(pysamdir, "stubs", 'AdjustmentFactors.pyi'),
                path.join(pysamdir, 'stubs', 'stubs', 'AdjustmentFactors.pyi'))

libfiles = []
for filename in listdir(path.join(pysamdir, 'stubs', 'stubs')):
    libfiles.append(filename)

setup(
    name='NREL-PySAM-stubs',
    version=latest_version,
    url='http://www.github.com/nrel/pysam',
    description="National Renewable Energy Laboratory's System Advisor Model Python Wrapper, stub files",
    long_description=long_description,
    long_description_content_type='text/markdown',
    license='BSD 3-Clause',
    author="dguittet",
    author_email="dguittet@nrel.gov",
    include_package_data=True,
    packages=['PySAM-stubs'],
    package_dir={'PySAM-stubs': 'stubs/stubs'},
    package_data={
        '': libfiles},
    zip_safe=False
)

