#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;
#include "Deck.h"
#include "Card.h"

bool hasPair(const vector<Card> &);
ostream & operator<<(ostream &os, const vector<Card> &theDeal);
double monteCarlo(int pairs, int numDeals);

int main () {
    srand(2222);
  
    ofstream outFS;
    string filename;
    string outputHands;
    int numCards = 0;
    int numDeals = 0;
    int pairs = 0;
    Deck deal;
    vector <Card> theDeal;
  
    cout << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> outputHands;
    cout << endl;
  
    if (outputHands == "Yes" || outputHands == "yes") {
        cout << "Enter name of output file: ";
        cin >> filename;
        cout << endl;
  
        outFS.open(filename);
  
        if (!outFS.is_open()) {
            cout << "Error opening " << filename << endl;
            exit(1);
        }
    }
  
    cout << "Enter number of cards per hand: ";
    cin >> numCards;
    cout << endl;
    cout << "Enter number of deals (simulations): ";
    cin >> numDeals;
    cout << endl;
  
    for (int i = 0; i < numDeals; ++i) {
        deal.shuffleDeck();
        theDeal.clear();
        for (int j = 0; j < numCards; ++j) {
            theDeal.push_back(deal.dealCard());
        }
        if (hasPair(theDeal)) {
            ++pairs;
            outFS << "Found Pair!! ";
        }
        else {
        outFS << "             ";
        }
        if (outputHands == "Yes" || outputHands == "yes") {
            outFS << theDeal << endl;
        }
    }
  
    cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << monteCarlo(pairs, numDeals) << "%" << endl;
  
    outFS.close();
  
    return 0;
}

bool hasPair(const vector<Card> &theDeal) {
    bool pair = false;
    for (unsigned i = 0; i < theDeal.size(); ++i) {
        for (unsigned j = i + 1; j < theDeal.size(); ++j) {
            if (theDeal.at(i).getRank() == theDeal.at(j).getRank()) {
                pair = true;
            }
        }
    }
    return pair;
}

ostream & operator<<(ostream &os, const vector<Card> &theDeal) {
    for (unsigned i = 0; i + 1 < theDeal.size(); ++i) {
        os << theDeal.at(i) << ", ";
    }
    os << theDeal.at(theDeal.size() - 1);
  
    return os;
}

double monteCarlo(int pairs, int numDeals) {
    return 100.0 * (static_cast<double>(pairs) / numDeals);
}