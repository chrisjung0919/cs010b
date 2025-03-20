#include "IntList.h"
#include "SortedSet.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Testing IntList class:\n";
    IntList list;
    list.push_back(5);
    list.push_back(10);
    list.push_front(3);
    list.insert_ordered(7);
    cout << "List after insertions: " << list << endl;
    list.remove_duplicates();
    cout << "List after removing duplicates: " << list << endl;
    list.selection_sort();
    cout << "Sorted List: " << list << endl;

    cout << "\nTesting SortedSet class:\n";
    SortedSet set1;
    set1.add(10);
    set1.add(5);
    set1.add(15);
    cout << "Set 1: " << set1 << endl;

    SortedSet set2;
    set2.add(7);
    set2.add(10);
    set2.add(3);
    cout << "Set 2: " << set2 << endl;

    SortedSet unionSet = set1 | set2;
    cout << "Union of Set 1 and Set 2: " << unionSet << endl;

    SortedSet intersectionSet = set1 & set2;
    cout << "Intersection of Set 1 and Set 2: " << intersectionSet << endl;

    set1 |= set2;
    cout << "Set 1 after union-assignment with Set 2: " << set1 << endl;

    set1 &= intersectionSet;
    cout << "Set 1 after intersection-assignment with intersectionSet: " << set1 << endl;

    return 0;
}