#include "IntVector.h"
#include <iostream>

using namespace std;

IntVector::IntVector() {
    sz = cap = 0;
    data = nullptr;
}

IntVector::IntVector(unsigned size, int value) {
    sz = cap = size;
    data = new int[cap];

    for (unsigned int i = 0; i < cap; ++i) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    delete[] data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    return sz == 0;
}

const int & IntVector::at(unsigned index) const {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    return data[index];
}

const int & IntVector::front() const {
    return at(0);
}

const int & IntVector::back() const {
    return at(sz - 1);
}
