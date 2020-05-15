#!/bin/sh

#
# Building for Mac
#

# Building libssc and libSAM_api 
# requires SAM-Dev/CMakeList.txt that contains lk, wex, ssc and sam as subdirectories

mkdir -p ~/SAM-Dev/cmake-build-export
cd ~/SAM-Dev/cmake-build-export
cmake -DCMAKE_BUILD_TYPE=Export -DSAMAPI_EXPORT=1 --build .. --target SAM_api --use-stderr -- -j 6

# Building the PyPi packages
# requires Miniconda installed with an environment per Python version from 3.5 to 3.8

cd $PYSAMDIR
source ~/miniconda3/etc/profile.d/conda.sh
rm -rf build

for PYTHONENV in pysam_build_3.5 pysam_build_3.6 pysam_build_3.7 pysam_build_3.8
do
   conda activate $PYTHONENV
   yes | pip install -r tests/requirements.txt
   yes | pip uninstall NREL-PySAM NREL-PySAM-stubs
   python setup.py install
   pytest -s tests
   retVal=$?
   if [ $retVal -ne 0 ]; then
       echo "Error in Tests"
       exit 1
   fi
   python setup.py bdist_wheel
done
python setup_stubs.py bdist_wheel

#
# Building for Manylinux1
#

cd ..
docker pull quay.io/pypa/manylinux1_x86_64
docker run --name pysam --rm -v $(pwd):/io quay.io/pypa/manylinux1_x86_64 /io/pysam/build_manylinux1
