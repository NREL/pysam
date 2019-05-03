# PySAM Package

## Requirements
1. Python 3.5, 64 bit
2. Operating system:
	- MacOSX 10.7+
	- Most Linux
	- Windows 7, x64
3. CMake 2.8


## Structure

1. Python User Script (Python)
2. __PySAM Package (Python)__
3. __PySAM Extension (C)__
4. SAM API (C)
5. SAM Library & SSC API (C/C++)
6. SSC Library (C++)


## PySAM Extension

1. Uses Python's C API to create importable C extension. A PySAM Extension is a wrapper module that exposes the SAM C API in a more "Pythonic" API that makes use of Python language features.
2. May not be compatible with different builds of the CPython reference interpreter, and not with alternative interpreters such as PyPy, IronPython or Jython 


## Error Handling

1. Most detailed error message is created by C API layer functions, inside `TranslateError()`, which throws exceptions upon failure of the C function. The error indication should be propagated up the callers, but without changing the message.


# Packaging

## Preparation

1. Versioning, updating README.md, generating stubs, testing


## Binary Distributions
1. PyPi Wheels
	- Mac & Windows
		```
		python setup.py bdist_wheel
		```

	- manylinux
		```
		docker pull quay.io/pypa/manylinux1_x86_64
		docker run -it -v $(pwd):/io quay.io/pypa/manylinux1_x86_64
		```
		- set SSCDIR, PYSAMDIR env vars
		- build libSAM_api.so and libssc.so and copy into ${PYSAMDIR}/data.
		- in ssc build directory
			```
			cmake28 /io/ssc -DCMAKE_BUILD_TYPE=Release -Dsystem_advisor_model_EXPORT=1
			```
		- repeat for sam build directory
			```
			cmake28 /io/sam/api -DCMAKE_BUILD_TYPE=Release -Dsystem_advisor_model_EXPORT=1
			```
		- build:
			```
			for PYBIN in /opt/python/*/bin; do
				"${PYBIN}/pip" wheel /io/PySAM -w wheelhouse/
  			done
		  	```
		- note: auditwheels does not work for this package since copies libSAM_api and libssc for each module... so manually rename wheels to `manylinux1`

	- Uploading
		```
		twine upload <file>
		```

2. Anaconda
	- requires `anaconda-navigator`, `conda-build` packages with `conda install <pkg>`
		```
		python setup.py bdist_conda
		anaconda upload -u nrel <file>
		```


### Installing
1. PyPi:
	```
	pip install NREL-PySAM
	```

3. Anaconda:
	```
	conda config --append channels NREL-PySAM
	conda install -c nrel nrel-pysam
	```
