#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   if(argc != 3){
   cout << "Usage: " << argv[0] << "" << endl;
      return 1;
   }

   string inputFile = argv[1];
   string outputFile = argv[2];

   ifstream inputStream;
   inputStream.open(inputFile);
   if(!inputStream.is_open()){
      cout << "Error: Could not open input file " << inputFile << endl;
      exit(EXIT_FAILURE);
   }

   vector<int> numbers;
   int num;
   char comma;

   while(inputStream >> num){
      numbers.push_back(num);
      inputStream >> comma;
   }
   inputStream.close();

   int sum = 0;
    for (unsigned int i = 0; i < numbers.size(); ++i) {
        sum += numbers[i];
    }

    int average = sum / numbers.size();

    for (unsigned int i = 0; i < numbers.size(); ++i) {
        numbers[i] = numbers[i] - average;
    }

    ofstream outputStream;
    outputStream.open(outputFile);
    if (!outputStream.is_open()) {
        cout << "Error: Could not open output file " << outputFile << endl;
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < numbers.size(); ++i) {
        outputStream << numbers[i];
        if (i < numbers.size() - 1) {
            outputStream << ",";
        }
    }
    outputStream.close();
   
   return 0;
}