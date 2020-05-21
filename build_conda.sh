#!/bin/bash

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh

# read version
VERSION="$(python -c 'from files.version import __version__; print(__version__)' 2>&1)"
export VERSION

for PYTHONENV in pysam_build_3.5 pysam_build_3.6 pysam_build_3.7 pysam_build_3.8
do
   conda activate $PYTHONENV
   conda install conda-build
   PYTHONVER="$(python -c 'import platform; major, minor, patch = platform.python_version_tuple(); print(major + "." + minor)')"
   PYSAMDIR=$PYSAMDIR SAMNTDIR=$SAMNTDIR conda-build . --output-folder=dist --python=$PYTHONVER || exit
   PYSAMDIR=$PYSAMDIR conda-build stubs --output-folder=dist --python=$PYTHONVER || exit
done
