// IntList.cpp
#include "IntList.h"
#include <iostream>

using namespace std;

IntList::IntList() : head(nullptr), tail(nullptr) {}

IntList::IntList(const IntList &other) : head(nullptr), tail(nullptr) {
    copy(other);
}

IntList &IntList::operator=(const IntList &other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

IntList::~IntList() {
    clear();
}

const int &IntList::front() const {
    return head->value;
}

const int &IntList::back() const {
    return tail->value;
}

bool IntList::empty() const {
    return head == nullptr;
}

void IntList::push_front(int value) {
    IntNode *newNode = new IntNode(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void IntList::push_back(int value) {
    IntNode *newNode = new IntNode(value);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

void IntList::selection_sort() {
    for (IntNode *i = head; i != nullptr; i = i->next) {
        IntNode *minNode = i;
        for (IntNode *j = i->next; j != nullptr; j = j->next) {
            if (j->value < minNode->value) {
                minNode = j;
            }
        }
        swap(i->value, minNode->value);
    }
}

void IntList::insert_ordered(int value) {
    if (empty() || value <= head->value) {
        push_front(value);
    } else if (value >= tail->value) {
        push_back(value);
    } else {
        IntNode *prev = head;
        IntNode *curr = head->next;
        while (curr != nullptr && curr->value < value) {
            prev = curr;
            curr = curr->next;
        }
        IntNode *newNode = new IntNode(value);
        prev->next = newNode;
        newNode->next = curr;
    }
}

void IntList::remove_duplicates() {
    IntNode *curr = head;
    while (curr != nullptr) {
        IntNode *runner = curr;
        while (runner->next != nullptr) {
            if (runner->next->value == curr->value) {
                IntNode *temp = runner->next;
                runner->next = runner->next->next;
                delete temp;
            } else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
}

IntNode *IntList::min(IntNode *start) {
    if (!start) return nullptr;
    IntNode *minNode = start;
    for (IntNode *curr = start->next; curr != nullptr; curr = curr->next) {
        if (curr->value < minNode->value) {
            minNode = curr;
        }
    }
    return minNode;
}

void IntList::copy(const IntList &other) {
    for (IntNode *curr = other.head; curr != nullptr; curr = curr->next) {
        push_back(curr->value);
    }
}

ostream &operator<<(ostream &out, const IntList &list) {
    IntNode *curr = list.head;
    while (curr != nullptr) {
        out << curr->value;
        if (curr->next != nullptr) {
            out << " ";
        }
        curr = curr->next;
    }
    return out;
}