#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;

int main(void) {
  {
    std::cout << "===CLAV===\n";
    ClapTrap trap("trap");

    trap.attack("some unlucky barrel");
    trap.takeDamage(10);
    trap.beRepaired(10);
  }
  {
    std::cout << "===SCAV===\n";
    ScavTrap scav("scav");
    ScavTrap cloneScav = scav;

    scav.attack("some unlucky BARREL");
    scav.takeDamage(10);
    scav.beRepaired(10);
    scav.guardGate();
  }
  {
    std::cout << "===FRAG===\n";
    FragTrap frag("frag");
    FragTrap cloneFrag = frag;

    frag.attack("cheese");
    frag.takeDamage(10);
    frag.beRepaired(10);
    frag.highFivesGuys();
  }
}