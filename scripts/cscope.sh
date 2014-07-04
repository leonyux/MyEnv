
MPWD=`pwd`

if [ $1 ]; then
    rm -rf cscope
    mkdir cscope
    find ${MPWD}/$1 -regex ".*\.c*[chx]" > cscope/cscope.files
    cd cscope
    cscope -bq
    cd ${MPWD}
fi

CSCOPE_DB=${MPWD}/cscope/cscope.out
export CSCOPE_DB

