clang-format -i -style=llvm $1
g++ -g -std=c++11 $1 -o ./a.out && ./a.out

