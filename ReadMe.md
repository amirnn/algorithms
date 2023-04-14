# Algorithms Using C++

## How to build

To build run the command below
```shell
# For Debug
conan install . --build=missing --profile=brew-llvm -s build_type=Debug
# or for Release
conan install . --build=missing --profile=brew-llvm -s build_type=Release
```
