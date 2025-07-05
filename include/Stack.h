#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

class Stack {
public:
    Stack();
    ~Stack();

    void push(int value);
    int pop();
    int peek() const;
    bool isEmpty() const;

private:
    LinkedList list;
};

#endif // STACK_H
