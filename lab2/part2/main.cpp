#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

int charCnt(const string& filename, char ch);

int main() {
   string filename;
   char ch;
   int chCnt = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   cout << "Enter a character: ";
   cin.ignore(); // ignores newline left in stream after previous input statement
   cin.get(ch);
   cout << endl;

   chCnt = charCnt(filename, ch);   
   cout << "# of " << ch << "'s: " << chCnt << endl;
   
   return 0;
}

int charCnt(const string& filename, char ch) {
   ifstream inputFile;
   int count = 0;
   char currentChar;

   inputFile.open(filename);
   if (!inputFile.is_open()) {
      cout << "Error opening " << filename << endl;
      exit(EXIT_FAILURE);
   }

   while (inputFile.get(currentChar)) {
      if (currentChar == ch) {
         count++;
      }
   }

   inputFile.close();
   return count;
}