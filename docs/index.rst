
NREL-PySAM
==========

NREL-PySAM is a wrapper for the National Renewable Energy Laboratory's `System Advisor Model <http://sam.nrel.gov>`_ (SAM), a simulator for renewable energy, not to be confused with `pysam <https://pysam.readthedocs.io/en/latest/api.html>`_, which is for reading sequence alignment files often used in genetics.

SAM is a performance and financial model designed to facilitate decision making for people involved in the renewable energy industry:

- Project managers and engineers
- Policy analysts
- Technology developers
- Researchers

`SAM <http://www.github.com/nrel/sam>`_ is open-source. PySAM provides a native Python interface for the models found in SAM Simulation Core, (`SSC <http://www.github.com/nrel/ssc>`_).


Getting Started
------------------------------------------

Learn how to install the package from PyPi or the Conda registry. Write your first PySAM script and run a renewable
energy power system simulation in a few steps following some examples. Or, take a look at how cases from the SAM Desktop
application can be imported into PySAM.

* **First steps**:
  :doc:`Installation and Import <GettingStarted>`

* **Creating models**
  :doc:`Examples <Examples>` |
  :doc:`Importing a case from SAM <Import>`


.. toctree::
   :maxdepth: 2
   :hidden:
   :caption: Getting Started

   /GettingStarted
   /Examples
   /Import


Models and Tools
------------------------------------------

PySAM offers all the technology and financial models available in SAM as separate modules. Learn about individual models
and how to chain models together to create a configuration. PySAM includes tools that provide design and resource functionality.

* **Technology and Financial Models**:
  :doc:`Available models <Models>` |
  :doc:`Configurations <Configs>` |


* **Tools**:
  :doc:`Design & Resource Tools <Tools>` |
  :doc:`PySSC Wrapper <PySSC>`


.. toctree::
   :maxdepth: 2
   :hidden:
   :caption: Models and Tools

   Models
   Configs
   Tools


Release notes
--------------
For information on versions, updates and matching SAM releases, please see `Release notes <https://github.com/NREL/pysam/blob/master/RELEASE.md>`_

* **Version 2.0 and Upgrading from Older Versions**: Between major version changes, in addition to new features, modules and bug fixes, the group to which a variable belongs may change.


.. toctree::
   :maxdepth: 2
   :hidden:
   :caption: About Read the Docs

   PySSC

