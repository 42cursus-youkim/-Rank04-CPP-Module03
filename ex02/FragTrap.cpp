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

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy._name) {
  _hitPoints = copy._hitPoints;
  _energyPoints = copy._energyPoints;
  _attackDamage = copy._attackDamage;
  announce(green) << "from " << makeTag(copy._name) << green << " is here!!!!\n"
                  << end;
}

// Destructor
FragTrap::~FragTrap() {
  announce(red) << "is reduced to fragments\n" << end;
}

// Operators
FragTrap& FragTrap::operator=(const FragTrap& assign) {
  if (this != &assign) {
    announce(yellow) << "is now " << makeTag(assign._name) << yellow << "\n "
                     << end;
    _name = assign._name;
    _hitPoints = assign._hitPoints;
    _energyPoints = assign._energyPoints;
    _attackDamage = assign._attackDamage;
  }
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