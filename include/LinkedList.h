#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void add(void* value);
    void addToEnd(void* value);
    bool remove(void* value);
    void* get(int index) const;
    int size() const;

private:
    struct Node {
        void* data;
        Node* next;
    };

    Node* head;
    int length;
};

#endif // LINKED_LIST_H
