# PySAM Package

https://nrel-pysam.readthedocs.io

* Provides a wrapper around the SAM library that groups together the C API functions by technology or financial model into modules.
* Includes error-checking, explicit input and output definition, and conversion between Python data types.
* PySAM modules are compatible with PySSC, which is included as a subpackage. PySSC is the original wrapper used by SAM's code generator.
* Automatically assign default values to input parameters from SAM's default value database.
* Built-in documentation of models and parameters.


## Requirements
1. Python 3.5+, 64 bit
2. Operating system:
	- MacOSX 10.7+
	- Most Linux
	- Windows 7, x64
3. CMake 2.8


## Installing
1. PyPi:
	```
	pip install NREL-PySAM
	```

2. Anaconda (<2.0.2 only):
	```
	conda config --env --append channels nrel
	conda install nrel-pysam
	```
	(package via `conda-forge` channel upcoming)


## Usage Examples
- [Demo](https://github.com/NREL/pysam/blob/master/demo.py)
- [Importing a SAM case](https://nrel-pysam.readthedocs.io/en/latest/Import.html)
- [Examples](https://github.com/NREL/pysam/blob/master/Examples)


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


## Building, Packaging & Distribution

[Instructions on Wiki](https://github.com/NREL/pysam/wiki/Building,-Packaging-and-Distributing)
