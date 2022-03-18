
NREL-PySAM
==========

NREL-PySAM is a wrapper for the National Renewable Energy Laboratory's `System Advisor Model <http://sam.nrel.gov>`_ (SAM), a simulator for renewable energy, not to be confused with `pysam <https://pysam.readthedocs.io/en/latest/api.html>`_, which is for reading sequence alignment files often used in genetics.

SAM is a performance and financial model designed to facilitate decision making for people involved in the renewable energy industry:

- Project managers and engineers
- Policy analysts
- Technology developers
- Researchers

`SAM <http://www.github.com/nrel/sam>`_ is open-source. PySAM provides a native Python interface for the models found in SAM Simulation Core, (`SSC <http://www.github.com/nrel/ssc>`_).

PySAM enables developers to run the underlying unit modules that make up a simulation in SAM.
A single simulation may comprise a single module or a process chaining together multiple unit modules.
PySAM exposes these unit modules in a native Python interface so that they can be customized and embedded in software applications.

.. toctree::
    :maxdepth: 2
    :hidden:
    :caption: Contents:

    GettingStarted.rst
    VersionChanges.rst
    Initialization.rst
    Examples.rst
    Webinars.rst
    Models.rst
    Configs.rst
    Import.rst
    Tools.rst
    PySSC.rst

Release notes & Version Changes
-------------------------------
For information on versions, updates and matching SAM releases, please see `SAM Release notes <https://github.com/NREL/pysam/blob/master/RELEASE.md>`_

**Version 3.0 and Upgrading from Older Versions**: There are significant changes to the input variables for several modules.
 Please see `SSC Release Notes <https://nrel.github.io/ssc/doc/releasenotes.html>`_ for description of functionality and
 variable definition changes, and please see :doc:`PySAM Version Changes <VersionChanges>` for full list of changes per PySAM Module.

 Between major version changes, in addition to new features, modules and bug fixes, the group to which a variable belongs may change.


Getting Started
------------------------------------------

Learn how to install the package from PyPi or the Conda registry. Write your first PySAM script and run a renewable
energy power system simulation in a few steps following some examples. Or, take a look at how cases from the SAM Desktop
application can be imported into PySAM.

* **First steps**:
  :doc:`Installation <GettingStarted>` |
  :doc:`Model Initialization <Initialization>`

* **Tutorials**:
  :doc:`Examples <Examples>` |
  :doc:`Webinars <Webinars>`

Models and Tools
------------------------------------------

PySAM offers all the technology and financial models available in SAM as separate unit modules. Learn about individual modules
and how to chain them together to represent a specific configuration such as Distributed Wind or Single Owner PV + Battery.
PySAM also includes tools that provide design and resource functionality.

Technical help documentation for the SAM models is available from the `SAM Help Website <https://samrepo.nrelcloud.org/help/index.html>_`.

* **Models**:
  :doc:`Technology and financial Unit Modules <Models>`


* **Simulations**:
  :doc:`Building up Simulations corresponding to SAM Configurations <Configs>` |
  :doc:`Importing a Simulation from SAM <Import>`


* **Tools**:
  :doc:`Design & Resource Tools <Tools>` |
  :doc:`PySSC Wrapper <PySSC>`