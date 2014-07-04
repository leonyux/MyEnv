#!/bin/env bash

SUBDIR=FDDBBU/

if [ $2 ]; then
   SUBDIR=$2
fi

name=${1#*/}
fname=${name%%/*}
diff -r -Nu   --exclude="CVS" --exclude="cscope"  --exclude='*.[^chxm]*' --exclude="l3parser" $1/$SUBDIR $SUBDIR> $fname.diff 

vim $fname.diff
