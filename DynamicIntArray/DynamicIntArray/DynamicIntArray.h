//
//  DynamicIntArray.h
//

#ifndef DynamicIntArray_h
#define DynamicIntArray_h

#include <iostream>

class DynamicIntArray {
    int *A;
    unsigned int len;
    unsigned int capacity;
    
    public:
    DynamicIntArray();
    DynamicIntArray& operator=(const DynamicIntArray&);
    unsigned int length() const;
    void push_back(int num);
    int pop_back();
};

DynamicIntArray::DynamicIntArray() : A(new int[1]), len(1), capacity(1) {};

DynamicIntArray::DynamicIntArray(const DynamicIntArray& B) {
    A = new int[B.capacity];
    for(unsigned int i = 0; i < b.len; i++) {
        A[i] = B[i];
    }
    len = B.len;
    capacity = B.capacity;
}

DynamicIntArray::DynamicIntArray& operator=(const DynamicIntArray&) {
    
};

unsigned int DynamicIntArray::length() const {
    return len;
};

void DynamicIntArray::push_back(int num) {
    
};

int DynamicIntArray::pop_back() {
    
};

const int operator[](const unsigned int index) const {
    if(index >= len) {
        throw("Error: out of bounds.");
    }
    return A(index);
};

int& operator[](const unsigned int index) {
    if(index >= len) {
        throw("Error: out of bounds.");
    }
    return A(index);
};

#endif
