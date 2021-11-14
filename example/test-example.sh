#!/usr/bin/env bash

isOk(){
    echo " OK - $1"
}

check(){
    g++ $1 && ./a.out 1>/dev/null && isOk $1 || continue
}

BASEDIR=$(dirname $(realpath "$0"))
cd $BASEDIR

check "./cpp_example.cpp" || continue
check "./smart_ptr.cpp" || continue
check "./create_loadFrom_backup.cpp" || continue
#check "./transaction_Read_Committed.cpp" || continue # //todo

rm -f ./a.out ./backup.arn
