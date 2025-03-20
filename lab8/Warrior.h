#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior : public Character {
 private:
    string allegiance;

 public:
    Warrior(const string &name, double health, double attackStrength, const string &allegiance);
    void attack(Character &opponent) override;
};

#endif
