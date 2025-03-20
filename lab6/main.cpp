#include <iostream>
#include "IntVector.h"

using namespace std;

int main()
{
    IntVector emptyVector;

    cout << "\nEmpty Vector details:";
    cout << "\n-> Size: " << emptyVector.size();
    cout << "\n-> Capacity: " << emptyVector.capacity();
    cout << "\n-> isEmpty: ";
    if (emptyVector.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
    
    cout << "\nCreating vector1 of size 10 with values set to 1 ... \n";
    IntVector vector1(10, 1);

    cout << "\nVector1 details:";
    cout << "\n-> Size: " << vector1.size();
    cout << "\n-> Capacity: " << vector1.capacity();
    cout << "\n-> isEmpty: ";
    if (vector1.empty()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;
    
    cout << "\nVector1 Data:";
    for (unsigned i = 0; i < vector1.size(); ++i) {
        cout << "\n-> vector1.at(" << i << ") = " << vector1.at(i);
    }

    cout << "\n\nVector1.front() = " << vector1.front();
    cout << "\nVector1.back() = " << vector1.back();

    cout << "\n\nEnds\n";

    return 0;
}