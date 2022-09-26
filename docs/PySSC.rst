Working Directly with PySSC
=============================

PySSC is a wrapper for the `SAM Simulation Core (SSC) API <https://github.com/NREL/ssc/blob/develop/ssc/sscapi.h>`_ PySSC is part of the `SAM Software Development Kit (SDK) <https://sam.nrel.gov/sdk>`_. The PySAM package is built on PySSC.

The `SSC Guide <https://sam.nrel.gov/images/web_page_files/ssc_guide.pdf>`_ is a reference to SSC.

To use PySSC, import it with:

.. code:: python

    from PySAM.PySSC import PySSC

PySSC gives you more transparent and direct access to the SSC library than PySAM. It requires a good understanding of SSC. PySAM has supporting functions, such as those for accessing defaults and building configurations, that make it easier to build models without knowledge the underlying SSC library. Some situations where you would want to use PySSC instead of PySAM include:

* To work with a custom SSC library (``ssc.dll`` for Windows, ``ssc.dylib`` for Mac, or ``ssc.so`` for Linux)  `built from SSC <https://github.com/NREL/ssc/wiki>`_ with modified or different compute modules than an official NREL version of SSC.

* To facilitate debugging of SSC through Python. For example, in Visual Studio, you can use `"Attach to Process" <https://learn.microsoft.com/en-us/visualstudio/debugger/attach-to-running-processes-with-the-visual-studio-debugger?view=vs-2022>`_ to debug SSC from Python while SSC is running. See instructions below.

* To work with different versions of the SSC library. In PySSC, you can easily change the SSC version by pointing to a different version of the SSC library.

Use SAM's Code Generator for PySSC
-----------------------------------

To get started using PySSC directly, create a case in SAM for the model you want to build, and use the **Python 3** (or **Python 2**) option in SAM's code generator to generate Python code. You can then modify the code as needed for your model. See :doc:`inputs-from-sam` for more about SAM's code generator.

Debug SSC from Python using Visual Studio
------------------------------------------

1. Build a Release or Debug version of SSC using Visual Studio Community (VS), which will create a release or debug version of the SSC library (``ssc.dll`` or ``sscd.dll`` in Windows).

2. Add a breakpoint in VS where you would like to start debugging the C++ code.

3. In your Python code, change the DLL path to one of these newly built DLLs.

4. Add a breakpoint in your Python code after the initialization of PySSC, and run your Python code up to this breakpoint.

5. In VS, select **Debug > Attach to Process** and choose **Native Code**. Find the Python process and click **Attach**. There are multiple Python processes, so noting the ``ProcessID`` from the PySSC output and finding that ID is the best way.

6. Continue executing the Python code and it will enter the VS code environment and stop at the set breakpoint.


PySSC description
------------------

.. automodule:: PySAM.PySSC
    :members:
    :undoc-members:
