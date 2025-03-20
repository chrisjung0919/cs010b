#include "Elf.h"
#include <iostream>

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
    : Character(ELF, name, health, attackStrength), family(family) {}

void Elf::attack(Character &opponent) {
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (opp.family == this->family) {
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            return;
        }
    }

    double damage = (health / MAX_HEALTH) * attackStrength;
    cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    opponent.damage(damage);
    cout << opponent.getName() << " takes " << damage << " damage." << endl;
}
