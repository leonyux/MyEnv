
MPWD=`pwd`

if [ $1 ]; then
    rm -rf cscope
    mkdir cscope
    find ${MPWD}/FDDBBU -regex ".*\.c*[chx]" > cscope/cscope.files
    cd cscope
    cscope -bq
    cd ${MPWD}
fi

CSCOPE_DB=${MPWD}/cscope/cscope.out
export CSCOPE_DB


#alias for FDDBBU
BRANCH_HOME=$MPWD/FDDBBU/1Develope_Case/HX-BPU_R3
export BRANCH_HOME
#branch alias
alias osp="cd $BRANCH_HOME/firm/firmware/platform/osp/libs"
alias firm="cd $BRANCH_HOME/firm"
alias oam="cd $BRANCH_HOME/flash/software/platform/oam"
alias l3="cd $BRANCH_HOME/flash/software/l3/test/linux_proj"
