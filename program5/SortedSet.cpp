#include "SortedSet.h"

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &set) : IntList(set) {
    remove_duplicates();
}

SortedSet::SortedSet(const IntList &list) : IntList(list) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int value) const {
    for (IntNode *p = head; p != nullptr; p = p->next) {
        if (p->value == value) {
            return true;
        }
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &set) const {
    SortedSet result = *this;
    for (IntNode *p = set.head; p != nullptr; p = p->next) {
        result.add(p->value);
    }
    return result;
}

SortedSet SortedSet::operator&(const SortedSet &set) const {
    SortedSet result;
    for (IntNode *p = set.head; p != nullptr; p = p->next) {
        if (in(p->value)) {
            result.add(p->value);
        }
    }
    return result;
}

void SortedSet::add(int value) {
    IntNode *p = head;
    IntNode *prev = nullptr;
    while (p != nullptr && p->value < value) {
        prev = p;
        p = p->next;
    }
    if (p == nullptr || p->value != value) {
        IntNode *new_node = new IntNode(value);
        if (prev == nullptr) {
            new_node->next = head;
            head = new_node;
        } else {
            new_node->next = p;
            prev->next = new_node;
        }
    }
}

void SortedSet::push_front(int value) {
    add(value);
}

void SortedSet::push_back(int value) {
    add(value);
}

void SortedSet::insert_ordered(int value) {
    add(value);
}

void SortedSet::remove_duplicates() {
    for (IntNode *p = head; p != nullptr; p = p->next) {
        IntNode *q = p->next;
        IntNode *prev = p;
        while (q != nullptr) {
            if (q->value == p->value) {
                prev->next = q->next;
                delete q;
                q = prev->next;
            } else {
                prev = q;
                q = q->next;
            }
        }
    }
}