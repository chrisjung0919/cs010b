#include <iostream>
using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      Rational add(const Rational &) const; 
      Rational subtract(const Rational &) const; 
      Rational multiply(const Rational &) const; 
      Rational divide(const Rational &) const;
      void simplify();
      void display() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

Rational::Rational() {
   this->numerator = 0;
   this->denominator = 1;
}

Rational::Rational(int num) {
   this->numerator = num;
   this->denominator = 1;
}

Rational::Rational(int num, int denom) {
   this->numerator = num;
   this->denominator = denom;
}

Rational Rational::add(const Rational &other) const {
    int new_numerator = this->numerator * other.denominator + other.numerator * this->denominator;
    int new_denominator = this->denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::subtract(const Rational &other) const {
    int new_numerator = this->numerator * other.denominator - other.numerator * this->denominator;
    int new_denominator = this->denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::multiply(const Rational &other) const {
    int new_numerator = this->numerator * other.numerator;
    int new_denominator = this->denominator * other.denominator;
    return Rational(new_numerator, new_denominator);
}

Rational Rational::divide(const Rational &other) const {
    int new_numerator = this->numerator * other.denominator;
    int new_denominator = this->denominator * other.numerator;
    return Rational(new_numerator, new_denominator);
}

void Rational::simplify() {
    int common_divisor = gcd(this->numerator, this->denominator);
    this->numerator /= common_divisor;
    this->denominator /= common_divisor;
    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }
}

void Rational::display() const {
    cout << this->numerator << " / " << this->denominator;
}

int Rational::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

