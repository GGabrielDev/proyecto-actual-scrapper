#include <cassert>
#include <iostream>
#include "DynamicArray.h"

void testAddAndGet() {
    DynamicArray array;
    array.add(10);
    array.add(20);
    array.add(30);

    assert(array.get(0) == 10);
    assert(array.get(1) == 20);
    assert(array.get(2) == 30);
}

void testSize() {
    DynamicArray array;
    assert(array.size() == 0);

    array.add(10);
    assert(array.size() == 1);

    array.add(20);
    assert(array.size() == 2);
}

int main() {
    testAddAndGet();
    testSize();
    std::cout << "All DynamicArray tests passed!" << std::endl;
    return 0;
}
