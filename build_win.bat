@ECHO OFF

cd %SSCDIR%
git checkout develop
echo y | git pull
cd %SAMNTDIR%
git checkout develop
echo y | git pull
cd %PYSAMDIR%
git checkout develop
echo y | git pull

mkdir %SSCDIR%\..\build_pysam
cd %SSCDIR%\..\build_pysam

REM skip api_autogen since the files should not need to be regenerated
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_CONFIGURATION_TYPES="Release" -DCMAKE_SYSTEM_VERSION=10.0 -Dskip_tools=1 -Dskip_tests=1 -Dskip_autogen=1 ..
devenv /build Release system_advisor_model.sln

cd %PYSAMDIR%
echo y | rmdir build /s

FOR %%i IN (pysam_build_3.5, pysam_build_3.6 pysam_build_3.7, pysam_build_3.8) DO (
	call deactivate
    call activate %%i
    echo y | pip install -r tests/requirements.txt
    echo y | pip uninstall NREL-PySAM NREL-PySAM-stubs
    python setup.py install
    pytest -s tests
	if errorlevel 1 (
	   echo Error in Tests
	   exit /b %errorlevel%
	)
    python setup.py bdist_wheel
)

REM rmdir %SSCDIR%\..\build_pysam /s