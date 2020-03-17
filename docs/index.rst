.. PySAM documentation master file, created by
   sphinx-quickstart on Tue Apr 23 17:57:42 2019.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to NREL-PySAM's documentation!
=================================

NREL-PySAM is a wrapper for the National Renewable Energy Laboratory's `System Advisor Model <http://sam.nrel.gov>`_ (SAM), a simulator for renewable energy, not to be confused with `pysam <https://pysam.readthedocs.io/en/latest/api.html>`_, which is for reading sequence alignment files often used in genetics.

SAM is a performance and financial model designed to facilitate decision making for people involved in the renewable energy industry:

- Project managers and engineers
- Policy analysts
- Technology developers
- Researchers

`SAM <http://www.github.com/nrel/sam>`_ is open-source. PySAM provides a native Python interface for the models found in SAM Simulation Core, (`SSC <http://www.github.com/nrel/ssc>`_).


Getting Started
===============

Installation
^^^^^^^^^^^^
PySAM for Python 3.5 to 3.8, as NREL-PySAM, is available on PyPi. It is also available on Anaconda for MacOSX up to 3.8 and on Windows and Linux up to 3.7. NREL-PySAM-stubs is the stub file package providing auto-completion features.

To install from PyPi::

	pip install NREL-PySAM

To install from Anaconda, the NREL channel needs to be appended::

    conda config --env --append channels nrel
    conda install nrel-pysam

Writing Your First PySAM Script
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Before you write your first PySAM script it really helps to familiarize 
yourself with SAM.  If you are not already familiar with SAM, it is recommended
you install it, and run a simulation of interest to you.  SAM is a graphical user interface to the SAM Simulation Core library of models.  Using it provides an easy introduction to the simulations that can be done using the library.  PySAM is a python interface to the same SAM Simulation Core that allows you to customize SAM for your specific needs.

There is a lot of data needed to run a SAM simulation.  Entering that data with assignment statements in PySAM can be tedious.  One way to get a full set of data is to load the default setup.  This is good if your situation is close to the default.  Often, however, this is not the case.  Fortunately when your setup is significantly different than the default, you can enter the data using the SAM graphical user interface, and save that data to a JSON file, which can then be loaded by PySAM. You can then modify and use the data in PySAM with python as needed.

Though SAM is one program, it is made up of a number of simulation modules that are run 
sequentially by the SAM graphical user interface.  The particular modules that
are run are determined by the type of simulation you are doing.  In general,
technology models are followed by financial models.  For example,
if you are running a PVWatts Distributed Commercial simulation, the modules in
the order they should be run are
pvwattsv7, battwatts, utilityrate5, and cashloan.  To find which modules you
need and the order to run them, look at :doc:`Configs` and search for your simulation type.  


Each technology and financial model is its own module. Module documentation is in :doc:`Models` or refer to :ref:`modindex`.  Each module can be imported by::

	import PySAM.<PySAM Module>

The original Python SDK, :doc:`PySSC`, is bundled, and can be imported by::

	from PySAM.PySSC import PySSC

For examples of using PySAM modules, see :doc:`Examples` and the Examples folder of the source.


Version 2.0 and Upgrading from Older Versions
=============================================

Between major version changes, in addition to new features, modules and bug fixes, the group to which a variable belongs may change.
The groups should stabilize after the initial releases.
Please see :doc:`Version` for more details.


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
