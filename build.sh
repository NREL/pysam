#!/bin/bash

if [ `uname` == Linux ]; then
    if [ "$PY_VER" == "3.5" ]; then
        pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp35-cp35m-manylinux1_x86_64.whl
    elif [ "$PY_VER" == "3.6" ]; then
    	pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp36-cp36m-manylinux1_x86_64.whl
	elif [ "$PY_VER" == "3.7" ]; then
		pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp37-cp37m-manylinux1_x86_64.whl
	elif [ "$PY_VER" == "3.8" ]; then
		pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp38-cp38-manylinux1_x86_64.whl
	else
        echo "Python version must be between 3.5 - 3.8"
        exit 1
    fi
fi

if [ `uname` == Darwin ]; then
    if [ "$PY_VER" == "3.5" ]; then
        pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp35-cp35m-macosx_10_*_x86_64.whl
    elif [ "$PY_VER" == "3.6" ]; then
    	pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp36-cp36m-macosx_10_*_x86_64.whl
	elif [ "$PY_VER" == "3.7" ]; then
		pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp37-cp37m-macosx_10_*_x86_64.whl
	elif [ "$PY_VER" == "3.8" ]; then
		pip install $PYSAMDIR/dist/NREL_PySAM-$PKG_VERSION-cp38-cp38-macosx_10_*_x86_64.whl
	else
        echo "Python version must be between 3.5 - 3.8"
        exit 1
    fi
fi
