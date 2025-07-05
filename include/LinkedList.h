#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void add(int value);
    bool remove(int value);
    int get(int index) const;
    int size() const;

private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    int length;
};

#endif // LINKED_LIST_H
