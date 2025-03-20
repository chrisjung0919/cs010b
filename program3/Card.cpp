#include <iostream>
using namespace std;
#include "Card.h"

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char suitInput, int rankInput) {
    suitInput = tolower(suitInput);
  
    if (suitInput == 'c') {
        suit = 'c';
    }
    else if (suitInput == 'd') {
        suit = 'd';
    }
    else if (suitInput == 'h') {
        suit = 'h';
    }
    else if (suitInput == 's') {
        suit = 's';
    }
    else {
        suit = 'c';
    }
  
    if (rankInput > 13 || rankInput < 1) {
        rank = 2;
    }
    else {
        rank = rankInput;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &os, const Card &rhs) {
    string cardShape;

    if (rhs.rank == 1) {
        os << "Ace";
    }
    else if (rhs.rank == 11) {
        os << "Jack";
    }
    else if (rhs.rank == 12) {
        os << "Queen";
    }
    else if (rhs.rank == 13) {
        os << "King";
    }
    else {
        os << rhs.rank;
    }
  
    if (rhs.suit == 'c') {
        cardShape = "Clubs";
    }
    else if (rhs.suit == 'd') {
        cardShape = "Diamonds";
    }
    else if (rhs.suit == 'h') {
        cardShape = "Hearts";
    }
    else if (rhs.suit == 's') {
        cardShape = "Spades";
    }
  
    os << " of " << cardShape;
  
    return os;
}