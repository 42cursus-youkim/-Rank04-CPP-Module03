#include <iostream>
#include "ClapTrap.hpp"

using std::cout;

int main(void) {
  { ClapTrap voidTrap; }
  {
    ClapTrap trap("trap");

    trap.takeDamage(10);
    trap.beRepaired(10);
    trap.attack("some unlucky barrel");
  }
}