#!/bin/sh

#
# Building for Mac
#

# Building libssc and libSAM_api
# requires SAM-Dev/CMakeList.txt that contains lk, wex, ssc and sam as subdirectories

mkdir -p ~/SAM-Dev/cmake-build-export
cd ~/SAM-Dev/cmake-build-export || exit
cmake .. -DCMAKE_BUILD_TYPE=Export -DSAMAPI_EXPORT=1
cmake --build . --target SAM_api -j 6

# Building the PyPi and Anaconda packages
# requires Miniconda installed with an environment per Python version from 3.5 to 3.8

cd $PYSAMDIR || exit
source $(conda info --base)/etc/profile.d/conda.sh
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

#./build_conda.sh

#
# Building for Manylinux1
#

cd ..
docker pull quay.io/pypa/manylinux1_x86_64
docker run --rm -v $(pwd):/io quay.io/pypa/manylinux1_x86_64 /io/pysam/build_manylinux.sh
rename -s linux manylinux1 pysam/*-linux-*


#
# Building for Anaconda for Linux
#

#docker pull continuumio/anaconda
#docker run --rm -v $(pwd):/io continuumio/anaconda PYSAMDIR=/io/pysam /io/pysam/build_conda.sh
