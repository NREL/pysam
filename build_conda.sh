#!/bin/bash

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh

DIST_NAME=''
if [ `uname` = "Linux" ] ;
then
    DIST_NAME='linux-64'
elif [ `uname` = "Darwin" ] ;
then
    DIST_NAME='osx-64'
fi
rm -rf dist/$DIST_NAME

# read version
VERSION="$(python -c 'from files.version import __version__; print(__version__)' 2>&1)"
export VERSION

yes | conda install conda-build
conda activate base
for PYTHONVER in 3.5 3.6 3.7 3.8
do
   conda-build stubs --output-folder=dist --python=$PYTHONVER || exit
   conda build purge
done
anaconda upload -u nrel dist/$DIST_NAME/*pysam-stubs*.bz2 || exit
rm -rf dist/$DIST_NAME

for PYTHONVER in 3.5 3.6 3.7 3.8
do
   conda-build conda --output-folder=dist --python=$PYTHONVER || exit
   conda build purge
done
anaconda upload -u nrel dist/$DIST_NAME/*pysam*.bz2
