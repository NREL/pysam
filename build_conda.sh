#!/bin/bash

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh

# read version
VERSION="$(python -c 'from files.version import __version__; print(__version__)' 2>&1)"
export VERSION

# distribution direction where bdist_wheel outputs to
DIST_DIR=$(pwd)/dist
export DIST_DIR

yes | conda install conda-build
yes | conda activate base
conda update -n base -c defaults conda

for PYTHONVER in 3.8 3.9 3.10 3.11 3.12
do
   export PYTHONVER
   conda-build conda --output-folder=$DIST_DIR --python=$PYTHONVER --prefix-length=0 || exit
   conda build purge
done

