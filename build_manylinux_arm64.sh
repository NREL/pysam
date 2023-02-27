#!/bin/sh

export SSCDIR=/io/ssc
export SAMNTDIR=/io/sam
export PYSAMDIR=/io/pysam

/opt/python/cp37-cp37m/bin/pip install cmake
ln -s /opt/python/cp37-cp37m/bin/cmake /usr/bin/cmake

mkdir -p /io/build_linux_ssc
cd /io/build_linux_ssc
cmake ${SSCDIR} -DCMAKE_BUILD_TYPE=Release -DSAM_SKIP_TOOLS=1 -DSAMAPI_EXPORT=1 -DSAM_SKIP_TESTS=1 ../ssc/ || exit
make -j6

mkdir -p /io/build_linux_sam
cd /io/build_linux_sam
rm -rf *
cmake ${SAMNTDIR}/api -DCMAKE_BUILD_TYPE=Release -DSAMAPI_EXPORT=1 -DSAM_SKIP_AUTOGEN=1 ../sam/api || exit
make -j6

cd $PYSAMDIR
#for PYTHONENV in cp38-cp38 cp39-cp39 cp310-cp310 cp311-cp311
for PYTHONENV in cp311-cp311
do
   yes | /opt/python/$PYTHONENV/bin/pip install -r tests/requirements.txt
   yes | /opt/python/$PYTHONENV/bin/pip uninstall NREL-PySAM
   /opt/python/$PYTHONENV/bin/python setup_arm64.py install
   /opt/python/$PYTHONENV/bin/python -m pytest -s tests
   retVal=$?
   if [ $retVal -ne 0 ]; then
       echo "Error in Tests"
#       exit 1
   fi
   /opt/python/$PYTHONENV/bin/python setup_arm64.py bdist_wheel
done
