#include <iostream>
#include <fstream>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
   
   // verify file name provided on command line

   // open file and verify it opened

   // Declare an array of doubles of size ARR_CAP.

    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.

    
   // Call the mean function passing it this array and output the 
   // value returned.
    
   // Ask the user for the index (0 to size - 1) of the value they want to remove.

	
   // Call the display function to output the array.

   
   // Call the remove function to remove the value at the index
   // provided by the user.
  
    
   // Call the display function again to output the array
   // with the value removed.

   
   // Call the mean function again to get the new mean

   //Lab 5 Code

   if (argc < 2) {
      cerr << "Error: No file provided." << endl;
      return 1;
   }

   ifstream inputFile;
   inputFile.open(argv[1]);

   if (!inputFile) {
      cerr << "Error: Could not open file." << endl;
      return 1;
   }

   double array[ARR_CAP];
   int arraySize = 0;
    
   while (arraySize < ARR_CAP && inputFile >> array[arraySize]) {
      arraySize++;
   }

   inputFile.close();

   cout << "Mean: " << mean(array, arraySize) << endl;

   int index;
   cout << "Enter index of value to be removed (0 to " << arraySize - 1 << "): ";
   cin >> index;

   cout << endl;

   if (index < 0 || index >= arraySize) {
      cerr << "Error: Index out of range." << endl;
      return 1;
   }
   
   cout << "Before removing value: ";
   display(array, arraySize);
   cout << endl;
   
   remove(array, arraySize, index);

   cout << "After removing value: ";
   display(array, arraySize);

   cout << endl;

   cout << "Mean: " << mean(array, arraySize) << endl;

	return 0;
}

double mean(const double array[], int arraySize){
   if(arraySize == 0){

   return 0;
   
   }

   double sum = 0;

   for(int i = 0; i < arraySize; i++){
      sum += array[i];
   }

   return sum/arraySize;

}

void remove(double array[], int &arraySize, int index){

   if(index < 0 || index > arraySize - 1 || arraySize <= 0){
      return;
   }

   for(int i = index; i < arraySize - 1; i++){
      array[i] = array[i+1];
   }

   arraySize -= 1;

}

void display(const double array[], int arraySize){
   for(int i = 0; i < arraySize; i++){
      cout << array[i];

      if(i < arraySize - 1){
         cout << ", ";
      }

   }
}