#include <iostream>
#include "ClapTrap.hpp"

using std::cout;

int main(void) {
  { ClapTrap voidTrap; }
  {
    ClapTrap trap("trap");

    trap.takeDamage(10);
    trap.attack("barrel");
  }
  {
    ClapTrap trap("repairTrap");
    for (int i = 0; i < 16; i++) {
      trap.beRepaired(10);
    }
  }
  {
    ClapTrap trap("attackTrap");
    for (int i = 0; i < 16; i++) {
      trap.attack("barrel");
    }
  }
}