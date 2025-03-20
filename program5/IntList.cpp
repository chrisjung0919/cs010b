#include "IntList.h"

using namespace std;

IntList::IntList() : head(nullptr), tail(nullptr) {}

IntList::~IntList() {
    clear();
}

IntList::IntList(const IntList& cpy) : head(nullptr), tail(nullptr) {
    const IntNode* curr = cpy.head;
    while (curr != nullptr) {
        push_back(curr->value);
        curr = curr->next;
    }
}

IntList& IntList::operator=(const IntList& rhs) {
    if (this != &rhs) {
        clear();
        const IntNode* curr = rhs.head;
        while (curr != nullptr) {
            push_back(curr->value);
            curr = curr->next;
        }
    }
    return *this;
}

void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

bool IntList::empty() const {
    return head == nullptr;
}

const int& IntList::front() const {
    if (!empty()) {
        return head->value;
    }
    throw runtime_error("Accessing front of an empty list.");
}

const int& IntList::back() const {
    if (!empty()) {
        return tail->value;
    }
    throw runtime_error("Accessing back of an empty list.");
}

void IntList::push_back(int value) {
    IntNode* newNode = new IntNode(value);
    if (empty()) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void IntList::clear() {
    while (!empty()) {
        pop_front();
    }
}

void IntList::selection_sort() {
    if (empty()) {
        return;
    }

    IntNode* i = head;
    while (i != nullptr) {
        IntNode* min = i;
        IntNode* j = i->next;

        while (j != nullptr) {
            if (j->value < min->value) {
                min = j;
            }
            j = j->next;
        }

        if (i != min) {
            swap(i->value, min->value);
        }
        i = i->next;
    }
}

void IntList::insert_ordered(int value) {
    if (empty() || head->value > value) {
        push_front(value);
        return;
    }

    IntNode* newNode = new IntNode(value);
    IntNode* prev = nullptr;
    IntNode* curr = head;

    while (curr != nullptr && curr->value <= value) {
        prev = curr;
        curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;

    if (curr == nullptr) {
        tail = newNode;
    }
}

void IntList::remove_duplicates() {
    if (empty()) {
        return;
    }

    IntNode* current = head;
    while (current != nullptr) {
        IntNode* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->value == current->value) {
                IntNode* duplicate = runner->next;
                runner->next = duplicate->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }

    tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }
}

ostream& operator<<(ostream& out, const IntList& rhs) {
    const IntNode* current = rhs.head;
    while (current != nullptr) {
        out << current->value;
        if (current->next != nullptr) {
            out << " ";
        }
        current = current->next;
    }
    return out;
}