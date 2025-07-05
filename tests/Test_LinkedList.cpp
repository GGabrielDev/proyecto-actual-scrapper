#include <cassert>
#include <iostream>
#include "LinkedList.h"

void testAddAndGet() {
    LinkedList list;
    int* value1 = new int(10);
    int* value2 = new int(20);
    int* value3 = new int(30);

    list.add(static_cast<void*>(value1));
    list.add(static_cast<void*>(value2));
    list.add(static_cast<void*>(value3));

    assert(*static_cast<int*>(list.get(0)) == 30);
    assert(*static_cast<int*>(list.get(1)) == 20);
    assert(*static_cast<int*>(list.get(2)) == 10);

    // Clean up
    delete value1;
    delete value2;
    delete value3;
}

void testRemove() {
    LinkedList list;
    int* value1 = new int(10);
    int* value2 = new int(20);
    int* value3 = new int(30);

    list.add(static_cast<void*>(value1));
    list.add(static_cast<void*>(value2));
    list.add(static_cast<void*>(value3));

    assert(list.remove(static_cast<void*>(value2)) == true);
    assert(list.size() == 2);
    assert(*static_cast<int*>(list.get(0)) == 30);
    assert(*static_cast<int*>(list.get(1)) == 10);

    int* value4 = new int(40);
    assert(list.remove(static_cast<void*>(value4)) == false);
    delete value4;  // Clean up

    // Clean up
    delete value1;
    delete value3;
}

void testSize() {
    LinkedList list;
    assert(list.size() == 0);

    int* value1 = new int(10);
    list.add(static_cast<void*>(value1));
    assert(list.size() == 1);

    int* value2 = new int(20);
    list.add(static_cast<void*>(value2));
    assert(list.size() == 2);

    // Clean up
    delete value1;
    delete value2;
}

int main() {
    testAddAndGet();
    testRemove();
    testSize();
    std::cout << "All LinkedList tests passed!" << std::endl;
    return 0;
}
