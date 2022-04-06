#include "FragTrap.hpp"
#include <iomanip>
#include <iostream>

using std::cout;

// Constructors
FragTrap::FragTrap() : ClapTrap("(VOID)") {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  announce() << "is here!!!!\n" END;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  announce() << "is here!!!!\n" END;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {}

// Destructor
FragTrap::~FragTrap() { announce(RED) << "is reduced to fragments!!\n" END; }

// Operators
FragTrap& FragTrap::operator=(const FragTrap& assign) {
  ClapTrap::operator=(assign);
  return *this;
}

void FragTrap::highFivesGuys() {
  announce(GRN) << "high fives guys!!!!!!\n" END;
}

std::ostream& FragTrap::announce(const std::string& color) {
  cout << color << "FragTrap " << std::left << BOLD << _name << " " << color;
  return cout;
}
