#!/bin/sh

export SSCDIR=/io/ssc
export SAMNTDIR=/io/sam
export PYSAMDIR=/io/pysam

/opt/python/cp37-cp37m/bin/pip install cmake
ln -s /opt/python/cp37-cp37m/bin/cmake /usr/bin/cmake

mkdir -p /io/build_linux_ssc
cd /io/build_linux_ssc
rm -rf *
cmake ${SSCDIR} -DCMAKE_BUILD_TYPE=Export -DSAM_SKIP_TOOLS=1 -DSAMAPI_EXPORT=1 -DSAM_SKIP_TESTS=1 ../ssc/
make -j 6

mkdir -p /io/build_linux_sam
cd /io/build_linux_sam
# rm -rf *
cmake ${SAMNTDIR}/api -DCMAKE_BUILD_TYPE=Export -DSAMAPI_EXPORT=1 -DSAM_SKIP_AUTOGEN=1 ../sam/api
make -j 6

cd $PYSAMDIR
for PYTHONENV in cp35-cp35m cp36-cp36m cp37-cp37m cp38-cp38 cp39-cp39
do
   yes | /opt/python/$PYTHONENV/bin/pip install -r tests/requirements.txt
   yes | /opt/python/$PYTHONENV/bin/pip uninstall NREL-PySAM NREL-PySAM-stubs
   /opt/python/$PYTHONENV/bin/python setup.py install
   /opt/python/$PYTHONENV/bin/python -m pytest -s tests
   retVal=$?
   if [ $retVal -ne 0 ]; then
       echo "Error in Tests"
       exit 1
   fi
   /opt/python/$PYTHONENV/bin/python setup.py bdist_wheel
done
