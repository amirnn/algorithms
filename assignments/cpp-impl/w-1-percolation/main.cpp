// Copyright 2025 by Amir Nourinia

#include <cstdlib>
#include <print>

import DSA;

int main() {
    datastructures::DynamicArray<double> array;
    array.pushFront(0.0);
    std::print("Array is {}", array.at(0));
    return EXIT_SUCCESS;
}

