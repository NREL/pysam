# PySAM Package

## Requirements
1. Python 3.5, 64 bit
2. Operating system:
	- Mac: macosx-10.7-x86_64
	- most linux distributions
	- Windows, 3.5
3. CMake 2.8


## Structure

1. Python User Script (Python)
2. __PySAM Package (Python)__
3. __PySAM Extension (C)__
4. SAM API (C)
5. SAM Library & SSC API (C/C++)
6. SSC Library (C++)


## PySAM Extension

1. Uses Python's C API to create importable C extension. A PySAM Extension is a wrapper module that exposes the SAM C API in a more "Pythonic" API that makes use of Python language features. [1]
	- One particularly notable feature of C extensions is that, when they don’t need to call back into the interpreter runtime, they can release CPython’s global interpreter lock around long-running operations (regardless of whether those operations are CPU or IO bound). [4]


## Error Handling

1. Most detailed error message is created by C API layer functions, inside `TranslateError()`, which throws exceptions upon failure of the C function. The error indication should be propagated up the callers, but without changing the message. [1]
	- PyErr_* functions are called by the layer above the C API, using message information from the C API. [14]
	- If PyErr_Clear() is called, then the extension layer is handling the error itself instead of passing it on.
	- Garbage must be cleaned when returning an error indication using `Py_XDECREF()`, which decrements the reference count for an object, whose destructor is called when the count is 0.


## Docstring
1. Declared for methods and objects, accessed via `x.__doc__` or `help(x)`


## Pythonic Arguments
1. Dictionary of values as argument to constructors [15]
	- Mutable default arguments are evaluated once only at function definition time and then becomes a (mutable) property of the function. Always make all `PyObject*` references to default arguments `static`.
	- Objects returned from PyArg_ParseTuple are borrowed, do not decrement reference count.


## PySAM Package

1. Structure: [7]
		PySAM/                          Top-level package
			data/						
				sam.dll/.so					
				ssc.dll/.so
				defaults/				Binaries directory
					PVWatts_None.df
					Windpower_None.df
					...
			src/                 		Python Extension source 	
				PySAM_utils.h
				PVWatts.c
				Windpower.c
				...
			setup.py
			README.md
			LICENSE.md



## Binary Distribution

1. Publish pre-built binaries for common platforms [3]
	- manylinux provides a convenient way to distribute binary Python extensions as wheels on Linux [9]
2. Can be built from source (github)
3. May not be compatible with different builds of the CPython reference interpreter, and not with alternative interpreters such as PyPy, IronPython or Jython 
4. Speedier than using CFFI


## PyPi
1. PyPi prefers Wheels, a package format designed to ship libraries with compiled artifacts
2. The PySAM library source will be distributed also
3. Cross-platform packaging using setuptools [10]
	- setuptools is a (largely) drop-in replacement for distutils. Its most notable addition over the unmodified distutils tools was the ability to declare dependencies on other packages. It is currently recommended as a more regularly updated alternative to distutils that offers consistent support for more recent packaging standards across a wide range of Python versions. [5]
	- Packaging extension modules [8]

## Anaconda
1. Use conda tools [7]

## References
[1] https://docs.python.org/3/extending/extending.html
[2] https://packaging.python.org/overview/
[3] https://packaging.python.org/guides/packaging-binary-extensions/
[4] https://thomasnyberg.com/releasing_the_gil.html
[5] https://docs.python.org/3.8/distributing/index.html#distributing-index
[6] https://conda.io/projects/conda-build/en/latest/concepts/package-anatomy.html
[7] https://packaging.python.org/tutorials/packaging-projects/
[8] https://docs.python.org/2/distutils/setupscript.html#describing-extension-modules
[9] https://github.com/pypa/python-manylinux-demo
[10] https://stackoverflow.com/questions/31380578/how-to-avoid-building-c-library-with-my-python-package
[11] https://stackoverflow.com/questions/47380150/dealing-with-dylibs-when-distributing-python-packages
[12] https://github.com/matthew-brett/delocate
[13] https://docs.python.org/3.5/extending/windows.html
[14] https://pythonextensionpatterns.readthedocs.io/en/latest/exceptions.html
[15] https://pythonextensionpatterns.readthedocs.io/en/latest/parsing_arguments.html#being-pythonic-with-default-arguments

## Testing distribution

### Packaging
1. Mac
	- python3 setup.py bdist_wheel

2. manylinux
	- docker pull quay.io/pypa/manylinux1_x86_64
	- docker run -it -v $(pwd):/io quay.io/pypa/manylinux1_x86_64
	- docker: build libSAM_api.so and libssc.so, copy into ${PYSAMDIR}/data.
		-- in ssc build directory: `cmake28 /path/to/ssc -DCMAKE_BUILD_TYPE=Release -Dsystem_advisor_model_EXPORT=1`
		-- repeat for sam build directory
	- docker:	`for PYBIN in /opt/python/*/bin; do
    				"${PYBIN}/pip" wheel /io/PySAM -w wheelhouse/
	  			done`
	- docker: auditwheels does not work for multimodule packages since it ends up copying libSAM_api and libssc for each module...
		-- `echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/io/PySAM/lib' >> ~/.bashrc`
		-- `source ~/.bashrc`
		-- `ldconfig`
		-- `auditwheel repair (wheel_name).whl`
	- https://github.com/pypa/python-manylinux-demo/blob/master/travis/build-wheels.sh

3. Windows

### Uploading
python3 -m twine upload --repository-url https://test.pypi.org/legacy/ dist/PowerPlant-1.0-cp37-cp37m-macosx_10_14_x86_64.whl

### Installing
1. If creating a virtual environment:
	Unix:
	- python3 -m virtualenv env
	- source env/bin/activate

	Windows:
	- py -m virtualenv env
	- .\env\Scripts\activate

2. pip3 install --index-url https://test.pypi.org/simple/ --no-deps PowerPlant

### Using
1. python3 import PowerPlant