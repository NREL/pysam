from distutils.core import setup, Extension

setup(name='keywdarg', version='1.0', \
      ext_modules=[Extension('keywdarg', ['keywdarg.c'])])