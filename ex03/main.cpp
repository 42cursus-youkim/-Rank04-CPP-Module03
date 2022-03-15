#include <iostream>
#include "DiamondTrap.hpp"

using std::cout;

int main(void) {
  DiamondTrap dia("dia");

  dia.attack("cheese");
  dia.takeDamage(10);
  dia.beRepaired(10);
  dia.highFivesGuys();
}