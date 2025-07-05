#include "DynamicArray.h"
#include <cassert>

DynamicArray::DynamicArray() : data(nullptr), capacity(0), length(0) {}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::add(int value) {
    if (length == capacity) {
        resize();
    }
    data[length++] = value;
}

int DynamicArray::get(int index) const {
    assert(index >= 0 && index < length);
    return data[index];
}

int DynamicArray::size() const {
    return length;
}

void DynamicArray::resize() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    int* newData = new int[capacity];
    for (int i = 0; i < length; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}
