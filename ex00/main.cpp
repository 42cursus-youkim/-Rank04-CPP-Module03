#include <iostream>
#include "ClapTrap.hpp"

using std::cout;

int main(void) {
  ClapTrap trap("trap");
  ClapTrap copiedTrap(trap);
  ClapTrap assignedTrap("before");

  assignedTrap = trap;

  trap.takeDamage(10);
  trap.beRepaired(10);
  trap.attack("some unlucky barrel");

  copiedTrap.takeDamage(3);
  copiedTrap.beRepaired(4);
  copiedTrap.attack("beer");
}