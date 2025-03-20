#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() : head(nullptr), tail(nullptr) { }

IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void IntList::clear() {
    while (head != nullptr) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void IntList::push_front(int NewNode) {
    IntNode* temp = new IntNode(NewNode);
    temp->next = this->head;
    this->head = temp;
    if (tail == nullptr) {
        tail = head;
    }
}

ostream& operator<<(ostream& out, const IntList& list1) {
    IntNode* curr = list1.head;

    while (curr != nullptr) {
        out << curr->value;
        curr = curr->next;

        if (curr != nullptr) {
            out << " ";
        }
    }

    return out;
}

void IntList::pop_front() {
    if (head != nullptr) {
        IntNode *temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

bool IntList::empty() const {
    return (head == nullptr);
}

const int& IntList::front() const {
    return head->value;
}

const int& IntList::back() const {
    return tail->value;
}
