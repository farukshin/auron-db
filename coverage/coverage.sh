g++ --coverage coverage.cpp -o cov.out && ./cov.out
lcov -t "cov" -o cov.info -c -d .
genhtml -o report cov.info