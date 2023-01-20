PySAM Overview
==========================================

PySAM is a Python package for the National Renewable Energy Laboratory's `System Advisor Model (SAM) <https://sam.nrel.gov>`_. It is part of the `SAM Software Development Kit (SDK) <https://sam.nrel.gov/software-development-kit>`_, which provides tools for developers who write code that interacts with the SAM Simulation Core (SSC) application programming interface (API).

SSC, SAM, and PySAM are NREL open source code projects hosted on GitHub.com.

`SSC <https://github.com/nrel/ssc>`_ is a library of performance and financial "compute modules" for modeling renewable energy projects. The SSC API is defined in the C header file, `sscapi.h <https://github.com/NREL/ssc/blob/develop/ssc/sscapi.h>`_.

`SAM <https://github.com/nrel/sam>`_ is a desktop application with a graphical user interface that provides user access to the SSC inputs and outputs, manages SSC inputs, and provides additional functions for modeling tasks such as sizing system components, calculating SSC inputs from user interface inputs, and parametric and stochastic simulations.

`PySAM <https://github.com/nrel/pysam>`_ is a Python package built on the PySSC wrapper for SSC. PySAM provides access to SSC inputs and outputs with some additional functions for building renewable energy models in Python.

The PySAM GitHub repository includes `code examples <https://github.com/NREL/pysam/tree/master/Examples>`_ of some common tasks.

.. important::

    SAM's user interface performs internal calculations to size system components, calculate values for SSC inputs, and other functions that are either not part of SSC or are integrated into the SSC compute modules in a way that is not transparent. Before you create a model in PySAM, create it in SAM and run test simulations to verify that the model works as you expect. Then set it up in PySAM and compare results with SAM. See xxxGotcha for more details.

Recordings of `NREL webinars on PySAM <https://sam.nrel.gov/pysam>`_ are available on the SAM website, along with more information and documentation about SAM.

For help with PySAM, please use the `SAM SDK and PySAM forum <https://sam.nrel.gov/forum/forum-sdk.html>`_. If you are an NREL researcher getting started using PySAM, please `contact SAM Support for guidance <mailto:sam.support@nrel.gov?subject='PySAM%20Support'>`_.
