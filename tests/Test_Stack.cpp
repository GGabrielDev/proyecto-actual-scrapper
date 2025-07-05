#include <cassert>
#include <iostream>
#include "Stack.h"

void testPushAndPop() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.pop() == 30);
    assert(stack.pop() == 20);
    assert(stack.pop() == 10);
}

void testPeek() {
    Stack stack;
    stack.push(10);
    stack.push(20);

    assert(stack.peek() == 20);
    stack.pop();
    assert(stack.peek() == 10);
}

void testIsEmpty() {
    Stack stack;
    assert(stack.isEmpty() == true);

    stack.push(10);
    assert(stack.isEmpty() == false);

    stack.pop();
    assert(stack.isEmpty() == true);
}

int main() {
    testPushAndPop();
    testPeek();
    testIsEmpty();
    std::cout << "All Stack tests passed!" << std::endl;
    return 0;
}
