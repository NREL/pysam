#!/bin/bash

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh

# get `CONDA_TOKEN` env variable, required for authentication
source .env || exit

DIST_NAME=''
if [ `uname` = "Linux" ] ;
then
    DIST_NAME='linux-64'
elif [ `uname` = "Darwin" ] ;
then
    DIST_NAME='osx-64'
else
    DIST_NAME='win-64'
fi
rm -rf dist/$DIST_NAME

# read version
VERSION="$(python -c 'from files.version import __version__; print(__version__)' 2>&1)"
export VERSION

# distribution direction where bdist_wheel outputs to
DIST_DIR=$(pwd)/dist
export DIST_DIR

yes | conda install conda-build
conda activate base
for PYTHONVER in 3.6 3.7 3.8 3.9
do
   conda-build stubs --output-folder=$DIST_DIR --python=$PYTHONVER || exit
   conda build purge
done
anaconda -t $CONDA_TOKEN upload -u nrel dist/$DIST_NAME/*pysam-stubs*.bz2 || exit
rm -rf dist/$DIST_NAME

for PYTHONVER in 3.6 3.7 3.8 3.9
do
   export PYTHONVER
   conda-build conda --output-folder=$DIST_DIR --python=$PYTHONVER --prefix-length=0 || exit
   conda build purge
done
anaconda -t $CONDA_TOKEN upload -u nrel dist/$DIST_NAME/*pysam*.bz2

conda build purge