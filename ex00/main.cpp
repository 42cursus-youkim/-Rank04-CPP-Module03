#include <iostream>
#include "ClapTrap.hpp"

using std::cout;

int main(void) {
  ClapTrap trap("trap");
  ClapTrap defaultTrap;
  ClapTrap copiedTrap(trap);

  trap.takeDamage(10);
  trap.beRepaired(10);
  trap.attack("some unlucky barrel");

  defaultTrap.takeDamage(1234);
  defaultTrap.beRepaired(100);
  defaultTrap.attack("cheese");

  copiedTrap.takeDamage(3);
  copiedTrap.beRepaired(4);
  copiedTrap.attack("beer");
}