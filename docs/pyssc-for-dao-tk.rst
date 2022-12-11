Building PySAM for NREL DAO-Tk
=================================================================================================

DAO-TK is the `Design, Analysis, and Operations Toolkit (DAO-Tk) <https://github.com/NREL/dao-tk>`_.

These instructions are for building a special version of PySAM for DAO-Tk for use with NREL LORE.

Compile only a Linux SSC library file (libssc.so) when using PySSC instead of PySAM
--------------------------------------------------------------------------------------------------

1. Check out desired ssc branch (i.e., mjwagner2/ssc:daotk-develop).

2. Build Release version of SSC (to at least verify no errors in Windows build), but first unload the following projects:

    * TCSConsole

    * SDKtool

3. Install Docker, start Docker Desktop, and switch to Linux containers if needed.


    If Docker does not have enough memory to start Linux containers:

        1. Download `RAMMap <https://docs.microsoft.com/en-us/sysinternals/downloads/rammap>`_ from the Microsoft Sysinternals tool set.

        2. In RAMMap, choose: **Empty -> Empty Working Sets** then **File -> Refresh**.

3. Open **Settings -> General** and *uncheck* **Use the WSL 2 based engine**.

4. Pull the manylinux1 container by opening a command prompt and running:

    .. code-block:: bash

       docker pull quay.io/pypa/manylinux1_x86_64

5. Then change the directory:

    >> code-block:: bash

        cd path/to/sam_dev/

6. Run:

    .. code-block:: bash

       docker run --rm -dit -v %cd%:/io quay.io/pypa/manylinux1_x86_64 /sbin/init

7. Run/start a manylinux container based on the built image by running the following command, replacing with the output id from the above command:

    .. code-block:: bash

       docker exec -it <id> bash -l

8. Paste the following commands into the bash window (right-click to paste). Be sure to copy the trailing end-of-line character, or you will have to press Enter once the last command is reached.

    .. code-block:: bash

       #!/bin/sh

       export SSCDIR=/io/ssc

       /opt/python/cp37-cp37m/bin/pip install cmake
       ln -s /opt/python/cp37-cp37m/bin/cmake /usr/bin/cmake

       mkdir -p /io/build_linux_ssc
       cd /io/build_linux_ssc
       rm -rf *
       cmake ${SSCDIR} -DCMAKE_BUILD_TYPE=Export -Dskip_tools=1 -DSAMAPI_EXPORT=1 -Dskip_tests=1 ../ssc/
       make -j 6

9. Ctrl-D to exit shell prompt.

10. Find the compiled Linux library ``libssc.so`` in ```path/to/sam_dev/build_linux_ssc/ssc``.

Install the DAO-Tk Version of PySAM (in a fresh environment)
--------------------------------------------------------------------------------------------------

1. Create new environment, initializing with Python 3.7:

    .. code-block:: bash

       conda create --name pysam_daotk python=3.7 -y

2. Activate that environment:

    .. code-block:: bash

       conda activate pysam_daotk

3. Install dao-tk and dao-tk stubs:

    .. code-block:: bash

       pip install nrel-pysam-dao-tk

This will install ``nrel-pysam-dao-tk-stubs`` automatically as a dependency.

Test the DAO-Tk Version of PySAM in VS Code
--------------------------------------------------------------------------------------------------

1. Open ``path/to/lore/pysam/mspt.py`` in VSCode.

2. Select interpreter in VS Code:

    1. In the blue status bar at the bottom of the window, click on the text of the current Python interpreter.

    2. In the new drop-down at the top of VSCode, select the interpreter specific to the Python environment you just created, e.g.:

        .. code-block:: bash

           Python 3.7.8 64-bit ('pysam_daotk': conda)

3. Select environment in terminal, if not automatically activated:

    .. code-block:: bash

       conda activate pysam_daotk

4. Run ``mspt.py``.

Creating a DAO-Tk Version of PySAM: Windows and Linux Builds
--------------------------------------------------------------------------------------------------

First time only setup
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Clone the `PySAM repository <https://github.com/NREL/pysam>`_ into ``path/to/sam_dev/pysam``.

2. Set the environment variable for pysam:

   +----------+-----------------------+
   | PYSAMDIR | path/to/sam_dev/pysam |
   +----------+-----------------------+

3. Register at `PyPI.org <https://pypi.org/>`_.

4. In ``path/to/lore/pysam/files/``, edit the arguments to ``setup()`` at the bottom of ``setup.py`` and ``stubs/setup.py``. Example:

    .. code-block:: bash

       name='NREL-PySAM-DAO-Tk' [append '-stubs' for /stubs/setup.py]
       ...
       url='https://github.com/NREL/dao-tk'
       description="National Renewable Energy Laboratory's DAO-Tk Python Wrapper" [append ', stub files' for /stubs/setup.py]
       ...
       author="Matthew-Boyd"
       author_email="matthew.boyd@nrel.gov"
       ...
       packages=['PySAM-DAO-Tk'], [append '-stubs' for /stubs/setup.py]
       package_dir={'PySAM-DAO-Tk': 'files'}, [change to: {'PySAM-DAO-Tk-stubs': 'stubs/stubs'} for stubs file]
       ...
       install_requires=['NREL-PySAM-DAO-Tk-stubs'],

*Windows*

5a. Add the location of devenv.exe to the system environment variables PATH, e.g.:

    .. code-block:: bash

       C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\

5b. Create new Python environments for versions 3.5 to the present (e.g., 3.8) by opening an Anaconda prompt and running:

    .. code-block:: bash

       conda create --name pysam_build_3.5 python=3.5 -y
       conda create --name pysam_build_3.6 python=3.6 -y
       conda create --name pysam_build_3.7 python=3.7 -y
       conda create --name pysam_build_3.8 python=3.8 -y

*Linux*

5a. Install Docker.

5b. Start Docker Desktop, switching to Linux containers if not already set to that.

    If Docker does not have enough memory to start Linux containers:

        1. Download `RAMMap <https://docs.microsoft.com/en-us/sysinternals/downloads/rammap>`_ from the Microsoft Sysinternals tool set.

        2. In RAMMap, choose **Empty -> Empty Working Sets** then **File -> Refresh**.

5c. Pull the manylinux1 container by opening a command prompt and running:

    .. code-block:: bash

       docker pull quay.io/pypa/manylinux1_x86_64

First time and after
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. Check out and pull the DAO-Tk repo/branch(es).

2. Update PySAM via a pull.

3. Delete the ``path/to/sam_dev/pysam/build`` directory if it exists.

4. Delete the contents of ``path/to/sam_dev/pysam/dist/```.

5. Copy config.h to ``path/to/sam_dev/ssc/nlopt`` if the file does not exist.

6. Copy CMakeLists.txt from ``path/to/lore/pysam/sam_files/`` to ``path/to/sam_dev/sam/api/``, replacing the file there.

7. Run the following commands in the ``path/to/sam_dev`` directory (e.g., in a ``.bat`` file) to delete the contents of ``path/to/sam_dev/build`` and run CMake in that directory to create the DAO-Tk code solution (`step 7.4 <https://github.com/NREL/SAM/wiki/Windows-Build-Instructions#7-run-cmake-to-generate-sam-vs-2019-project-files>`_).

    .. code-block:: bash

       rmdir /Q/S build
       mkdir build
       cd build
       cmake -G "Visual Studio 16 2019" -DCMAKE_CONFIGURATION_TYPES="Release" -DCMAKE_SYSTEM_VERSION=10.0 -DSAMAPI_EXPORT=1 -DSAM_SKIP_AUTOGEN=0 ..

8. Open ``/build/system_advisor_model.sln`` in Visual Studio and perform a batch-build of the Release configuration, but first unload the following projects:

    * TCSConsole

    * SDKtool

    Doing an entire build including exporting the API can take 45 minutes, so please be patient. Once the build is finished, you should have the SAM and ssc libraries (``ssc.dll``, ``ssc.lib`` and ``SAM_api.dll``, ``SAM_api.lib``) in the folder ``path/to/sam_dev/pysam/files/`` . However, there may be build errors that need to be fixed.

9. In ``path/to/lore/pysam/files/``:

    1. Edit the ``/files/version.py`` and ``/stubs/files/version.py`` files:

        * Increment the version (major.minor.patch).

        * Version must not equal any previous versions or PyPI will not let it on the repo.

    2. Edit ``RELEASE.md``, adding the most recent changes.

10. Copy the entire contents of ``path/to/lore/pysam/files`` to ``path/to/sam_dev/pysam/``, overriding all the respective files.

11. Open ``path/to/sam_dev/pysam/modules/WaveFileReader.c`` and fix string continuation error on line starting with "Load wave resource data from file...".

*Windows*

12a. Run ``path/to/sam_dev/pysam/build_win.bat`` to build pysam, install the nrel-pysam-dao-tk package for the different Python versions locally and to create the corresponding wheel (``.whl``) files. There may be a couple test errors. If you recently built pysam, you can comment out the following lines (``REM``) in ``build_win.bat`` to save time:

   .. code-block:: bash

       mkdir %SSCDIR%\..\build_pysam
       cd %SSCDIR%\..\build_pysam
       cmake -G "Visual Studio 16 2019" -DCMAKE_CONFIGURATION_TYPES="Release" -DCMAKE_SYSTEM_VERSION=10.0 -Dskip_tools=1 -Dskip_tests=1 ..
       devenv /build Release system_advisor_model.sln

*Linux*

12a. Start Docker Desktop for Linux containers if it is not running.

12b. In a command prompt:

    .. code-block:: bash

        cd path/to/sam_dev/

12c. To build automatically:

    .. code-block:: bash

       docker run --rm -v %cd%:/io quay.io/pypa/manylinux1_x86_64 /io/pysam/build_manylinux.sh

12d. To run manually (debug):

    1. Build manylinux image by running:

        .. code-block:: bash

           docker run --rm -dit -v %cd%:/io quay.io/pypa/manylinux1_x86_64 /sbin/init

    2. Run/start a manylinux container based on the built image by running the following command, replacing <id> with the output from the above command.

        .. code-block:: bash

           docker exec -it <id> bash -l

    3. Copy commands from ``build_manylinux.sh`` to the bash window (right-click to paste) to step through the script. Be sure to copy the trailing end-of-line character, or you will have to press Enter once the last command is reached.

12e. The four resulting Linux wheels corresponding to the different Python versions are put in ``path/to/sam-dev/pysam/dist/`` alongside the already existing Windows wheels and stub file.

12f. Ctrl-D to exit shell prompt

*Windows and Linux*

13. Open an Anaconda prompt and cd to ``%PYSAMDIR%\dist``.

14. Rename the new Linux wheels so PyPI accepts their upload:

    .. code-block:: bash

       rename *-linux_x86_64* *-manylinux1_x86_64*

15. Upload the Python wheels to PyPI, first ensuring you are not connected to a proxy (e.g., NREL Pulse Secure):

    .. code-block:: bash

       pip install twine
       twine upload %PYSAMDIR%\dist\*.whl

16. Clear your local changes to the official PySAM *and* SAM packages by running the following in Git for both repos:

    .. code-block:: bash

       git checkout -- .
       git clean -fd

17. Commit the changes to the ``RELEASE.md`` and the two ``version.py`` files and push to the lore repo.

.. note::
    If there are issues with PySAM, check out previous correlated versions of `PySAM <https://github.com/NREL/pysam/tags>`_ and `SAM <https://github.com/NREL/SAM/tags>`_ from their respective repos for this custom PySAM build. Reference the repo tags to verify version correlation.
