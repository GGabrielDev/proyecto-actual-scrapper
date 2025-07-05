#include "Stack.h"
#include <cassert>

Stack::Stack() {}

Stack::~Stack() {}

void Stack::push(int value) {
    list.add(value);
}

int Stack::pop() {
    assert(!isEmpty() && "Stack underflow");
    int value = list.get(0);
    list.remove(value);
    return value;
}

int Stack::peek() const {
    assert(!isEmpty() && "Stack is empty");
    return list.get(0);
}

bool Stack::isEmpty() const {
    return list.size() == 0;
}
