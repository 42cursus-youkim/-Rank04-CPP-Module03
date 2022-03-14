#include <iostream>
#include "ScavTrap.hpp"

using std::cout;

int main(void) {
  {
    std::cout << "===CLAV===\n";
    ClapTrap trap("trap");

    trap.takeDamage(10);
    trap.beRepaired(10);
    trap.attack("some unlucky barrel");
  }
  {
    std::cout << "===SCAV===\n";
    ScavTrap scav("scav");

    scav.attack("some unlucky BARREL");
    scav.takeDamage(10);
    scav.beRepaired(10);
  }
}