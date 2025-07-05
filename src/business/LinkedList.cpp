#include "LinkedList.h"
#include <cassert>

LinkedList::LinkedList() : head(nullptr), length(0) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::add(void* value) {
    Node* newNode = new Node{value, head};
    head = newNode;
    ++length;
}

bool LinkedList::remove(void* value) {
    Node** current = &head;
    while (*current != nullptr) {
        if ((*current)->data == value) {
            Node* toDelete = *current;
            *current = (*current)->next;
            delete toDelete;
            --length;
            return true;
        }
        current = &((*current)->next);
    }
    return false;
}

void* LinkedList::get(int index) const {
    assert(index >= 0 && index < length);
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

int LinkedList::size() const {
    return length;
}
