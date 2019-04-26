.. PySAM documentation master file, created by
   sphinx-quickstart on Tue Apr 23 17:57:42 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to PySAM's documentation!
=================================

PySAM is a wrapper for the National Renewable Energy Laboratory's `System Advisor Model <http://sam.nrel.gov>`_ (SAM).

SAM is a performance and financial model designed to facilitate decision making for people involved in the renewable energy industry:

- Project managers and engineers
- Policy analysts
- Technology developers
- Researchers

`SAM <http://www.github.com/nrel/sam>`_ is open-source. PySAM provides a native Python interface for the models found in SAM Simulation Core, `SSC <http://www.github.com/nrel/ssc>`_. 


Getting Started
===============

PySAM is available on PyPi and Anaconda (Windows and MacOSX only) as NREL-PySAM. NREL-PySAM-stubs is the stub file package providing autocompletion features.

To install from PyPi::

	pip install NREL-PySAM
	pip install NREL-PySAM-stubs

To install from Anaconda, the NREL channel needs to be appended::

	conda config --append channels NREL
	conda install -c nrel nrel-pysam

Each technology and financial model is its own module, which can be imported by::

	import PySAM.<PySAM Module>

The original Python SDK, PySSC, is bundled, and can be imported by::

	from PySAM.PySSC import PySSC

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

Create a new empty model::

	PySAM.<PySAM Module>.new()

Create a new model with values assigned from defaults::

	PySAM.<PySAM Module>.default(string configuration)

Built-in documentation is also available with help.

View parameter groups per class and available default values::

	help(PySAM.<PySAM Module>)

View descriptions of parameters in a group::

	help(PySAM.<PySAM Module>.<group>)


Available Models
===============================

For a table of available models, see :doc:`Models`, or refer to :ref:`modindex`.


SAM Configurations
==================================

For a table of SAM configurations and the sequence of models required to run them, see :doc:`Configs`.


Importing a SAM GUI Case
========================

For an example of how to import the modules and variables from a SAM GUI Case, see :doc:`Import`.


PySAM Documentation Pages
=========================
.. toctree::
   :maxdepth: 2

   PySSC
   Models
   Configs
   Import


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
