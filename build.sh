#!/bin/sh

# requires Miniconda installed with an environment per Python version from 3.5 to 3.8

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
