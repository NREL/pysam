#!/bin/sh

export SSCDIR=/io/ssc
export SAMNTDIR=/io/sam
export PYSAMDIR=/io/pysam

mkdir -p /io/build_linux_ssc
cd /io/build_linux_ssc
rm -rf *
cmake ${SSCDIR} -DCMAKE_BUILD_TYPE=Release -DSAM_SKIP_TOOLS=1 -DSAMAPI_EXPORT=1 -DSAM_SKIP_TESTS=1 ../ssc || exit
cmake --build . --target shared -j 6 || exit
cmake --build . --target ssc -j 6 || exit

mkdir -p /io/build_linux_sam
cd /io/build_linux_sam
rm -rf *
cmake ${SAMNTDIR}/api -DCMAKE_BUILD_TYPE=Release -DSAMAPI_EXPORT=1 -DSAM_SKIP_AUTOGEN=1 ../sam/api || exit
make -j 6 || exit

cd $PYSAMDIR
for PYTHONENV in cp39-cp39 cp310-cp310 cp311-cp311 cp312-cp312 cp313-cp313
do
   yes | /opt/python/$PYTHONENV/bin/pip install -r tests/requirements.txt
   yes | /opt/python/$PYTHONENV/bin/pip uninstall NREL-PySAM
   /opt/python/$PYTHONENV/bin/python setup.py install || exit
   /opt/python/$PYTHONENV/bin/python -m pytest -s tests
   retVal=$?
   if [ $retVal -ne 0 ]; then
       echo "Error in Tests"
       exit 1
   fi
   /opt/python/$PYTHONENV/bin/python setup.py bdist_wheel
done
