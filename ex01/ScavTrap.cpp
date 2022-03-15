#include "ScavTrap.hpp"
#include <iomanip>
#include <iostream>

using std::cout;

// Constructors
ScavTrap::ScavTrap() : ClapTrap("(VOID)") {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  announce(green) << "long for COMBAT!!!!!\n" << end;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  announce(green) << "long for COMBAT!!!!!\n" << end;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {}

// Destructor
ScavTrap::~ScavTrap() {
  announce(red) << "is BLASTED into oblivion!!!!!\n" << end;
}

// Operators
ScavTrap& ScavTrap::operator=(const ScavTrap& assign) {
  ClapTrap::operator=(assign);
  return *this;
}

void ScavTrap::attack(std::string const& target) {
  announce(yellow) << "attack " << makeTag(target) << yellow << ", causing "
                   << red << boldNum(_attackDamage) << yellow
                   << " points of DAMAGE! (and that was a lot)\n"
                   << end;
}

void ScavTrap::guardGate() {
  announce(yellow) << "entered GATE KEEPER MODE!!!\n";
}

std::ostream& ScavTrap::announce(std::string color) {
  cout << color << "ScavTrap " << std::left << std::setw(16) << makeTag(_name)
       << " " << color;
  return cout;
}