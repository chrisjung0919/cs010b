#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance)
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {}

void Warrior::attack(Character &opponent) {
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (opp.allegiance == this->allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            return;
        }
    }

    double damage = (health / MAX_HEALTH) * attackStrength;
    cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
    opponent.damage(damage);
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
}
