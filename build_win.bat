@ECHO OFF

mkdir %SSCDIR%\..\build_pysam
cd %SSCDIR%\..\build_pysam

REM skip api_autogen since the files should not need to be regenerated
cmake -G "Visual Studio 17 2022" -DCMAKE_CONFIGURATION_TYPES="Release" -DCMAKE_SYSTEM_VERSION=10.0 -DSAM_SKIP_TOOLS=1 -DSAM_SKIP_TESTS=1 -DSAM_SKIP_AUTOGEN=0 -DSAMAPI_EXPORT=1 ..
devenv /build Release system_advisor_model.sln /Project SAM_api
if errorlevel 1 (
    echo Error in Build
    exit /b %errorlevel%
)

cd %PYSAMDIR%
echo y | rmdir build /s
echo y | del dist\*

FOR %%i IN (pysam_build_3.9 pysam_build_3.10 pysam_build_3.11, pysam_build_3.12 pysam_build_3.13) DO (
	call deactivate
    call activate %%i
    echo y | pip install -r tests/requirements.txt
    echo y | pip uninstall NREL-PySAM
    python setup.py install
    pytest -s tests
	if errorlevel 1 (
	   echo Error in Tests
	   exit /b %errorlevel%
	)
    python setup.py bdist_wheel
)
REM %bash% build_conda.sh
REM anaconda upload -u nrel dist/*.tar.bz2

REM only upload to PyPi after Github Actions test of new package passes
REM twine upload dist/*.whl

REM rmdir %SSCDIR%\..\build_pysam /s
