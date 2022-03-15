#include <iostream>
#include "ClapTrap.hpp"

using std::cout;

int main(void) {
  ClapTrap trap("trap");
  ClapTrap voidTrap;

  trap.takeDamage(10);
  trap.beRepaired(10);
  trap.attack("some unlucky barrel");
}