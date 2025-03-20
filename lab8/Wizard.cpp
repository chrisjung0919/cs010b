#include "Wizard.h"
#include <iostream>

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
    : Character(WIZARD, name, health, attackStrength), rank(rank) {}

void Wizard::attack(Character &opponent) {
    double damage;

    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        damage = attackStrength * (static_cast<double>(rank) / opp.rank);
    } else {
        damage = attackStrength;
    }

    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    opponent.damage(damage);
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
}
