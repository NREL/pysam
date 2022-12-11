List of SSC Compute Modules
==========================================

A compute module is an executable performance model, financial model, or a module that provides functions called by other compute modules during a simulation.

See below for a list of SSC compute modules that you can access in PySAM.

(HD) indicates modules that are used to build any SAM configurations. These modules either contain helper functions called by other compute modules, or are deprecated older versions of compute modules. For example, the CbConstructionFinancing module is not in the execution sequence of any configurations, but it is used by some modules, such as TcsMSLF, to calculate construction financing cost during a simulation. Utilityrate4 is a deprecated version of Utilityrate5 that was used in older versions of SAM.

PySAM uses a slightly different naming convention for compute modules than SSC: PySAM module names are capitalized or use camel case (Pvwattsv8, TroughPhysical), and SSC module names are lower case with underscores (pvwattsv8, trough_physical).

.. include:: lists/models.rst
