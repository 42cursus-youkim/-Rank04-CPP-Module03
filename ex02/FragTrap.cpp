#include "FragTrap.hpp"
#include <iomanip>
#include <iostream>

using std::cout;

// Constructors
FragTrap::FragTrap() : ClapTrap("(VOID)") {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  announce(green) << "is here!!!!\n" << end;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  announce(green) << "is here!!!!\n" << end;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy) {}

// Destructor
FragTrap::~FragTrap() {
  announce(red) << "is reduced to fragments\n" << end;
}

// Operators
FragTrap& FragTrap::operator=(const FragTrap& assign) {
  ClapTrap::operator=(assign);
  return *this;
}

void FragTrap::attack(std::string const& target) {
  announce(yellow) << "attack " << makeTag(target) << yellow << ", causing "
                   << red << boldNum(_attackDamage) << yellow
                   << " points of damage!!!!!!\n"
                   << end;
}

void FragTrap::highFivesGuys() {
  announce(green) << "high fives guys!!!!!!\n" << end;
}

std::ostream& FragTrap::announce(std::string color) {
  cout << color << "FragTrap " << std::left << std::setw(16) << makeTag(_name)
       << " " << color;
  return cout;
}