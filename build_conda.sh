#!/bin/bash

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh

# read version
VERSION="$(python -c 'from files.version import __version__; print(__version__)' 2>&1)"
export VERSION

conda install conda-build
for PYTHONVER in 3.5 3.6 3.7 3.8
do
   PYSAMDIR=$PYSAMDIR conda-build . --output-folder=dist --python=$PYTHONVER || exit
   PYSAMDIR=$PYSAMDIR conda-build stubs --output-folder=dist --python=$PYTHONVER || exit
done
