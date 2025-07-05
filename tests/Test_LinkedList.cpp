#include <cassert>
#include <iostream>
#include "LinkedList.h"

void testAddAndGet() {
    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);

    assert(list.get(0) == 30);
    assert(list.get(1) == 20);
    assert(list.get(2) == 10);
}

void testRemove() {
    LinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);

    assert(list.remove(20) == true);
    assert(list.size() == 2);
    assert(list.get(0) == 30);
    assert(list.get(1) == 10);

    assert(list.remove(40) == false);
    assert(list.size() == 2);
}

void testSize() {
    LinkedList list;
    assert(list.size() == 0);

    list.add(10);
    assert(list.size() == 1);

    list.add(20);
    assert(list.size() == 2);
}

int main() {
    testAddAndGet();
    testRemove();
    testSize();
    std::cout << "All LinkedList tests passed!" << std::endl;
    return 0;
}
