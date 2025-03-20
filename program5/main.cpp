#include "IntList.h"
#include "SortedSet.h"
#include <iostream>

using namespace std;

int main() {
    SortedSet set1;
    set1.add(5);
    set1.add(3);
    set1.add(8);
    set1.add(3);

    cout << "Set 1: " << set1 << endl;

    SortedSet set2;
    set2.add(7);
    set2.add(3);
    set2.add(10);

    cout << "Set 2: " << set2 << endl;

    SortedSet unionSet = set1 | set2;
    cout << "Union of Set1 and Set2: " << unionSet << endl;

    SortedSet intersectionSet = set1 & set2;
    cout << "Intersection of Set1 and Set2: " << intersectionSet << endl;

    set1.insert_ordered(6);
    set1.insert_ordered(2);
    cout << "Set 1 after insert_ordered: " << set1 << endl;

    return 0;
}