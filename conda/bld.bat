SET PIP_NO_INDEX=0

SET OS_NAME=win

SET PYTHONVER=%PYTHONVER:.=%

SET pattern=NREL_PySAM-*%VERSION%*%PYTHONVER%*%OS_NAME%*whl

cd %DIST_DIR%

for %%a in (%pattern%) do set FILE=%%a

echo "file %FILE%"

if exist %FILE% (
    pip install %FILE%
) else (
    echo "%FILE% does not exist."
    exit 1
)
