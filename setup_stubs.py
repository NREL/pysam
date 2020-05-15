from setuptools import setup
import distutils
import sys
from files.version import __version__

latest_version = __version__

# determine if making PyPi or Conda distribution
distclass = distutils.core.Distribution
if sys.argv[1] == "bdist_conda":
    import distutils.command.bdist_conda
    distclass = distutils.command.bdist_conda.CondaDistribution

# prepare package description
from os import path, listdir
this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'RELEASE.md'), encoding='utf-8') as f:
    long_description = f.read()

libfiles = ['__init__.pyi']

for filename in listdir('stubs'):
    libfiles.append(filename)

setup(
    name='NREL-PySAM-stubs',
    version=latest_version,
    distclass=distclass,
    url='http://www.github.com/nrel/pysam',
    description="National Renewable Energy Laboratory's System Advisor Model Python Wrapper, stub files",
    long_description=long_description,
    long_description_content_type='text/markdown',
    license='BSD 3-Clause',
    author="dguittet",
    author_email="dguittet@nrel.gov",
    include_package_data=True,
    packages=['PySAM-stubs'],
    package_dir={'PySAM-stubs': 'stubs'},
    package_data={
        '': libfiles},
    zip_safe=False
)

