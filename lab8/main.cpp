#include <iostream>

using namespace std;

// Include the header files for the Warrior, Elf, and Wizard classes
#include "Warrior.h"
#include "Elf.h"
#include "Wizard.h"

int main() {
    // Create instances of Warrior with different names, health, strength, and allegiance
    Warrior w1("Arthur", 100, 5, "King George");
    Warrior w2("Jane", 100, 6, "King George");
    Warrior w3("Bob", 100, 4, "Queen Emily");

    // Create instances of Elf with different names, health, agility, and realm
    Elf e1("Raegron", 100, 4, "Sylvarian");
    Elf e2("Cereasstar", 100, 3, "Sylvarian");
    Elf e3("Melimion", 100, 4, "Valinorian");

    // Create instances of Wizard with different names, health, spell power, and mana
    Wizard wz1("Merlin", 100, 5, 10);
    Wizard wz2("Adali", 100, 5, 8);
    Wizard wz3("Vrydore", 100, 4, 6);

    // Elf e1 attacks Warrior w1
    e1.attack(w1);
    cout << endl;

    // Elf e1 attacks Elf e2
    e1.attack(e2);
    cout << endl;

    // Warrior w2 attacks Warrior w1
    w2.attack(w1);
    cout << endl;

    // Warrior w3 attacks Warrior w1
    w3.attack(w1);
    cout << endl;

    // Wizard wz1 attacks Wizard wz2
    wz1.attack(wz2);
    cout << endl;

    // Wizard wz1 attacks Wizard wz3
    wz1.attack(wz3);
    cout << endl;

    return 0;
}