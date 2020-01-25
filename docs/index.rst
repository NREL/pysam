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


Version 2.0 and Upgrading from Older Versions
=============================================

Between major version changes, in addition to new features, modules and bug fixes, the group to which a variable belongs may change.
The groups should stabilize after the initial releases.
Please see :doc:`Version` for more details.


Getting Started
===============

PySAM is available on PyPi and Anaconda (Windows and MacOSX only) as NREL-PySAM. NREL-PySAM-stubs is the stub file package providing autocompletion features.

To install from PyPi::

	pip install NREL-PySAM

To install from Anaconda, the NREL channel needs to be appended::

	conda config --append channels NREL
	conda install -c nrel nrel-pysam

Each technology and financial model is its own module, which can be imported by::

	import PySAM.<PySAM Module>

The original Python SDK, PySSC, is bundled, and can be imported by::

	from PySAM.PySSC import PySSC

For examples of using PySAM modules, see :doc:`Examples`

Available Models
===============================

For a table of available models, see :doc:`Models`, or refer to :ref:`modindex`.


SAM Configurations
==================================

For a table of SAM configurations and the sequence of models required to run them, see :doc:`Configs`.


PySAM Documentation Pages
=========================
.. toctree::
   :maxdepth: 2

   Models
   Configs
   Tools
   PySSC
   Examples
   Import


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
