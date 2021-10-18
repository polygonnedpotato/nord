rm ./nord
clang++-7 -pthread -std=c++17 -o nord main.cpp
chmod a=rwx nord
./nord