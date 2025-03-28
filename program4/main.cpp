#include <iostream>

#include "IntVector.h"

using namespace std;

int main () {
    IntVector Test;
    cout << "TESTING Variable Test ()" << endl;
    cout << "TESTING IntVector(), size(), capacity()" << endl;
    cout << "Expected: 0, 0" << endl;
    cout << "Actual:   " << Test.size() << ", " << Test.capacity() << endl;
    cout << "TESTING empty()" << endl;
    cout << "Expected: true (1)" << endl;
    cout << "Actual:         " << Test.empty() << endl;
    cout << "TESTING insert(), expand(), at(), front(), back() using insert(0, 7), at(0)" << endl;
    cout << "Expected: 7, 7, 7" << endl;
    Test.insert(0, 7);
    cout << "Actual:   " << Test.at(0) << ", " << Test.front() << ", " << Test.back() << endl;
    cout << "TESTING assign() using assign(3, 9), at(0), at(1), at(2)" << endl;
    cout << "Expected: 9, 9, 9, 3" << endl;
    Test.assign(3, 9);
    cout << "Actual:   " << Test.at(0) << ", " << Test.at(1) << ", " << Test.at(2) << ", " << Test.size() << endl;
    cout << "TESTING erase() using erase(1), at(0), at(1)" << endl;
    cout << "Expected: 9, 9, 2" << endl;
    Test.erase(1);
    cout << "Actual:   " << Test.at(0) << ", " << Test.at(1) << ", " << Test.size() << endl;
    cout << "TESTING push_back() using push_back(5)" << endl;
    cout << "Expected: 5, 3" << endl;
    Test.push_back(5);
    cout << "Actual:   " << Test.back() << ", " << Test.size() << endl;
    cout << "TESTING pop_back()" << endl;
    cout << "Expected: 9, 2" << endl;
    Test.pop_back();
    cout << "Actual:   " << Test.back() << ", " << Test.size() << endl;
    cout << "TESTING clear()" << endl;
    cout << "Expected: 0" << endl;
    Test.clear();
    cout << "Actual:   " << Test.size() << endl;
    cout << "TESTING resize() using resize(3, 4), at(0), at(1), at(2)" << endl;
    cout << "Expected: 4, 4, 4, 3" << endl;
    Test.resize(3, 4);
    cout << "Actual:   " << Test.at(0) << ", " << Test.at(1) << ", " << Test.at(2) << ", " << Test.size() << endl;
    cout << "TESTING reserve() using reserve(7)" << endl;
    cout << "Expected: 7" << endl;
    Test.reserve(7);
    cout << "Actual:   " << Test.capacity() << endl;

    cout << endl;
    IntVector Test2(4, 8);
    cout << "TESTING VARIABLE Test2 (4, 8)" << endl;
    cout << "TESTING IntVector(), size(), capacity(), front(), back(), at() using at(0), at(1), at(2), at(3)" << endl;
    cout << "Expected: 4, 4, 8, 8, 8, 8, 8, 8" << endl;
    cout << "Actual:   " << Test2.size() << ", " << Test2.capacity() << ", " << Test2.front() << ", " << Test2.back() << ", " << Test2.at(0) << ", " << Test2.at(1) << ", " << Test2.at(2) << ", " << Test2.at(3) << endl;
    cout << "TESTING empty()" << endl;
    cout << "Expected: false (0)" << endl;
    cout << "Actual:          " << Test2.empty() << endl;
    cout << "TESTING insert(), expand() using insert(2, 7), insert(3, 9), at(2), at(3), at(4)" << endl;
    cout << "Expected: 7, 9, 8, 6" << endl;
    Test2.insert(2, 7);
    Test2.insert(3, 9);
    cout << "Actual:   " << Test2.at(2) << ", " << Test2.at(3) << ", " << Test2.at(4) << ", " << Test2.size() << endl;
    cout << "TESTING erase() using erase(3) using at(2), at(3)" << endl;
    cout << "Expected: 7, 8, 5" << endl;
    Test2.erase(3);
    cout << "Actual:   " << Test2.at(2) << ", " << Test2.at(3) << ", " << Test2.size() << endl;
    cout << "TESTING assign() using assign(2, 3), at(0), at(1)" << endl;
    cout << "Expected: 3, 3, 2" << endl;
    Test2.assign(2, 3);
    cout << "Actual:   " << Test2.at(0) << ", " << Test2.at(1) << ", " << Test2.size() << endl;
    cout << "TESTING push_back() using push_back(5)" << endl;
    cout << "Expected: 5, 3" << endl;
    Test2.push_back(5);
    cout << "Actual:   " << Test2.back() << ", " << Test2.size() << endl;
    cout << "TESTING pop_back()" << endl;
    cout << "Expected: 3, 2" << endl;
    Test2.pop_back();
    cout << "Actual:   " << Test2.back() << ", " << Test2.size() << endl;
    cout << "TESTING clear()" << endl;
    cout << "Expected: 0" << endl;
    Test2.clear();
    cout << "Actual:   " << Test2.size() << endl;
    cout << "TESTING resize() using resize(4, 1)" << endl;
    cout << "Expected: 4, 1, 1" << endl;
    Test2.resize(4, 1);
    cout << "Actual:   " << Test2.size() << ", " << Test2.front() << ", " << Test2.back() << endl;
    cout << "TESTING reserve() using reserve(16)" << endl;
    cout << "Expected: 16" << endl;
    Test2.reserve(16);
    cout << "Actual:   " << Test2.capacity() << endl << endl;

    return 0;
}
