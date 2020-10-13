.. Initialization

Writing Your First PySAM Script
*******************************

Before you write your first PySAM script it really helps to familiarize yourself with SAM.
If you are not already familiar with SAM, it is recommended you install it, and run a simulation of interest to you.
Using it provides an easy introduction to the simulations that can be done using the library.

There is a lot of data needed to run a SAM simulation. Entering that data with assignment statements in PySAM can be tedious.
One way to get a full set of data is to load the default setup, explained below. This is good if your situation is close to the default.
Often, however, this is not the case. Fortunately when your setup is significantly different than the default,
you can enter the data using the SAM graphical user interface, and save that data to a JSON file, which can then be loaded by PySAM.
You can then modify and use the data in PySAM with python as needed. This is shown in :doc:`Import`.

The particular unit ``compute_modules`` that are run are determined by the type of simulation you are doing.
In general, technology models are followed by financial models.
To find which modules you need and the order to run them, look at :doc:`Configs` and search for your configuration type.


Initializing a Model
********************

Each technology and financial model is its own module. Module documentation is in :doc:`Models` or refer to :ref:`modindex`.
Each module can be imported by::

	import PySAM.<PySAM Module>


There are four methods to create a new instance of a PySAM module:

1. ``new()`` creates an instance with empty attributes.

2. ``default`` populates the models' attributes with default values specific to a technology-financial configuration in SAM.

3. ```from_existing`` shares underlying data with an existing PySAM object. If a default configuration name is provided,
the default attributes are loaded similar to ``default``.

4. ``wrap`` allows compatibility with PySSC, for details, refer to :doc: PySSC <PySSC>`. For its use in importing data
from SAM, see :doc:`Import`.
