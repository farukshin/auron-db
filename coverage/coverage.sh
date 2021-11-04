#!/usr/bin/env bash

error() {
    echo "Ошибка выполнения test coverage" >&2
    exit 1
}

BASEDIR=$(dirname $(realpath "$0"))
cd $BASEDIR

g++ --coverage coverage.cpp -o cov.out && ./cov.out \
    && lcov -t "cov" -o cov.info -c -d . \
    && genhtml -o report cov.info \
    && rm coverage.gcda coverage.gcno cov.out cov.info backup.arn \
    && rm -R report || error
