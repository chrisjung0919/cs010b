#include "IntList.h"

#include <iostream>

using namespace std;

IntList::IntList() : head(nullptr) {}

void IntList::push_front(int val) {
   if (!head) {
      head = new IntNode(val);
   } else {
      IntNode *temp = new IntNode(val);
      temp->next = head;
      head = temp;
   }
}

bool IntList::exists(int val) const {
    return exists(head, val);
}

bool IntList::exists(IntNode *node, int val) const {
    if (!node) {
        return false;
    }
    if (node->value == val) {
        return true;
    }
    return exists(node->next, val);
}

void printRecursive(ostream &out, IntNode *node) {
    if (!node) return;
    out << node->value;
    if (node->next) {
        out << " ";
    }
    printRecursive(out, node->next);
}

ostream & operator<<(ostream &out, const IntList &list) {
    printRecursive(out, list.head);
    return out;
}

ostream & operator<<(ostream &out, IntNode *node) {
    printRecursive(out, node);
    return out;
}
