#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip> //I typed this for setprecision and fixed

//Program 1 assignment final submission

using namespace std;

void readData(const string &filename, vector<double> &angles, vector<double> &coefficients);
double interpolation(double angle, const vector<double> &angles, const vector<double> &coefficients);
bool isOrdered(const vector<double> &angles);
void reorder(vector<double> &angles, vector<double> &coefficients);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <data_file>" << endl;
        return 1;
    }

    string filename = argv[1];


    vector<double> angleVal;
    vector<double> coefficientVal;

    readData(filename, angleVal, coefficientVal);

    if (!isOrdered(angleVal)) {
        reorder(angleVal, coefficientVal);
    }

    char userchoice = 'y';
    
    while (userchoice == 'y' || userchoice == 'Y') {
        double inputAngle;
        cout << "Enter a flight-path angle: ";
        if (!(cin >> inputAngle)) {
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "Invalid input. Please enter a valid number for the angle." << endl;
            continue;
        } else{

        double result = interpolation(inputAngle, angleVal, coefficientVal);

        cout << "The coefficient of lift for the angle " << inputAngle << " is " << fixed << setprecision(3) << result << endl;
        
        cout << "Do you want to enter another flight-path angle? (y/n): ";
        cin >> userchoice;
        }

        if (userchoice != 'y' && userchoice != 'Y') {
            break;
        }
    }
    return 0;
}

void readData(const string &filename, vector<double> &angles, vector<double> &coefficients) {
    ifstream inputFile;
    inputFile.open(filename);
    if (!inputFile.is_open()) {
        cout << "Error opening " << filename << endl;
        exit(EXIT_FAILURE);
    }

    double angle;
    double coefficient;


    while (inputFile >> angle >> coefficient) {
        angles.push_back(angle);
        coefficients.push_back(coefficient);
    }
    inputFile.close();
}

double interpolation(double angle, const vector<double> &angles, const vector<double> &coefficients) {
    if(angle <= angles.front()){
        return coefficients.front();
    }

    if(angle >= angles.back()){
        return coefficients.back();
    }
    
    for (unsigned int i = 0; i < angles.size() - 1; ++i) {
        if (angles[i] == angle) {
            return coefficients[i];
        }
        if (angles[i] < angle && angle < angles[i + 1]) {
            double a = angles[i];
            double c = angles[i + 1];
            double f_a = coefficients[i];
            double f_c = coefficients[i + 1];
            return f_a + ((angle - a) / (c - a)) * (f_c - f_a);
        }
    }
    return 0;
}

bool isOrdered(const vector<double> &angles) {
    for (unsigned int i = 1; i < angles.size(); ++i) {
        if (angles[i] < angles[i - 1]) {
            return false;
        }
    }
    return true;
}

void reorder(vector<double> &angles, vector<double> &coefficients) {
    vector<pair<double, double>> data;
    for (unsigned int i = 0; i < angles.size(); ++i) {
        data.push_back(make_pair(angles[i], coefficients[i]));
    }

    sort(data.begin(), data.end());

    for (unsigned int i = 0; i < data.size(); ++i) {
        angles[i] = data[i].first;
        coefficients[i] = data[i].second;
    }
}
