export PIP_NO_INDEX='False'

case $(uname | tr '[:upper:]' '[:lower:]') in
  linux*)
    export OS_NAME=manylinux1
    ;;
  darwin*)
    export OS_NAME=macosx
    ;;
  *)
    export OS_NAME=other
    ;;
esac

if [[ $OS_NAME == 'other' ]]; then
  printf '%s\n' "Unrecognized OS type" >&2
  exit 1
fi

pattern=$DIST_DIR/NREL_PySAM-*$VERSION*"${PYTHONVER//.}"*$OS_NAME*whl
FILE=( $pattern )
pattern=$DIST_DIR/NREL_PySAM_stubs-*$VERSION*whl
STUBS_FILE=( $pattern )

if [ -f "$FILE" ]; then
    pip install $STUBS_FILE
    pip install $FILE
else
    echo "$FILE does not exist."
    exit 1
fi
