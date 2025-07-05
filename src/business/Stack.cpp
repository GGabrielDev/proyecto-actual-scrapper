#include "Stack.h"
#include <cassert>

Stack::Stack() {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();  // Ensure all allocated memory is freed
    }
}

void Stack::push(int value) {
    int* newValue = new int(value);  // Allocate memory for the integer
    list.add(static_cast<void*>(newValue));
}

int Stack::pop() {
    assert(!isEmpty() && "Stack underflow");
    int* valuePtr = static_cast<int*>(list.get(0));
    int value = *valuePtr;
    list.remove(valuePtr);
    delete valuePtr;  // Free the allocated memory
    return value;
}

int Stack::peek() const {
    assert(!isEmpty() && "Stack is empty");
    int* valuePtr = static_cast<int*>(list.get(0));
    return *valuePtr;
}

bool Stack::isEmpty() const {
    return list.size() == 0;
}
