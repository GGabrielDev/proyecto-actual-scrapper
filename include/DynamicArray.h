#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

class DynamicArray {
public:
    DynamicArray();
    ~DynamicArray();

    void add(int value);
    int get(int index) const;
    int size() const;

private:
    int* data;
    int capacity;
    int length;

    void resize();
};

#endif // DYNAMIC_ARRAY_H
