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
	pip install nrel-pysam
	```

2. Anaconda (<1.2.1 only):
	```
	conda install -c nrel nrel-pysam nrel-pysam-stubs
	```

May not be compatible with different builds of the CPython reference interpreter, and not with alternative interpreters such as PyPy, IronPython or Jython

## Usage Examples
- [Importing a SAM case](https://nrel-pysam.readthedocs.io/en/latest/Import.html)
- [Examples](https://github.com/NREL/pysam/blob/master/Examples)


## Citing this package

PySAM Version 2.1.1. National Renewable Energy Laboratory. Golden, CO. Accessed May 27, 2020. https://github.com/nrel/pysam
