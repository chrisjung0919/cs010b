#include "SortedSet.h"

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &other) : IntList(other) {}

SortedSet::SortedSet(const IntList &list) : IntList(list) {
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int value) const {
    IntNode *current = head;
    while (current) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &other) const {
    SortedSet result(*this);
    IntNode *current = other.head;
    while (current) {
        result.add(current->value);
        current = current->next;
    }
    return result;
}

SortedSet SortedSet::operator&(const SortedSet &other) const {
    SortedSet result;
    IntNode *current = head;
    while (current) {
        if (other.in(current->value)) {
            result.add(current->value);
        }
        current = current->next;
    }
    return result;
}

void SortedSet::add(int value) {
    if (!in(value)) {
        insert_ordered(value);
    }
}

void SortedSet::push_front(int value) {
    add(value);
}

void SortedSet::push_back(int value) {
    add(value);
}

void SortedSet::insert_ordered(int value) {
    if (!in(value)) {
        IntList::insert_ordered(value);
    }
}

SortedSet &SortedSet::operator|=(const SortedSet &other) {
    *this = *this | other;
    return *this;
}

SortedSet &SortedSet::operator&=(const SortedSet &other) {
    *this = *this & other;
    return *this;
}