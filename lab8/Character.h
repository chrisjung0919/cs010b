#ifndef __CHARACTER_H__ // Include guard to prevent multiple inclusions
#define __CHARACTER_H__

#include <iostream>
#include <string>

using namespace std;

// Enum to define character types
enum CharType {WARRIOR, ELF, WIZARD};

// Constant for maximum health value
const double MAX_HEALTH = 100.0;

class Character {
 protected:
    CharType type;                // Type of the character (WARRIOR, ELF, WIZARD)
    string name;                  // Name of the character
    double health;                // Health value of the character
    double attackStrength;        // Attack strength of the character

 public:
    // Constructor to initialize a Character with type, name, health, and attackStrength
    Character(CharType type, const string &name, double health, double attackStrength);

    // Getter for character type
    CharType getType() const;

    // Getter for character name
    const string & getName() const;

    // Getter for character health, returns the health as an integer
    int getHealth() const;

    // Setter for character health
    void setHealth(double h);

    // Checks if the character is alive, i.e., health is greater than 0
    bool isAlive() const;

    // Pure virtual function for attack, to be defined in derived classes
    virtual void attack(Character &) = 0;
};

#endif // __CHARACTER_H__