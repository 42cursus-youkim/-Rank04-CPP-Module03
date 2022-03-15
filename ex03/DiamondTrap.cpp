#include "DiamondTrap.hpp"
#include <iomanip>
#include <iostream>

using std::cout;

// Constructors
DiamondTrap::DiamondTrap()
    : ClapTrap("(VOID)_clap_name"), ScavTrap(), FragTrap() {
  _name = "(VOID)";
  FragTrap::_hitPoints = 100;
  ScavTrap::_energyPoints = 50;
  FragTrap::_attackDamage = 30;
  announce(green) << "is shiny!!!!\n" << end;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
  _name = name;
  FragTrap::_hitPoints = 100;
  ScavTrap::_energyPoints = 50;
  FragTrap::_attackDamage = 30;
  announce(green) << "is shiny!!!!\n" << end;
}

// DiamondTrap::DiamondTrap(const DiamondTrap& copy) {}

// Destructor
DiamondTrap::~DiamondTrap() {
  announce(red) << "is no longer shiny!!!!\n" << end;
}

// Operators
// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& assign) {}

void DiamondTrap::attack(std::string const& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  announce(red) << "My name: " << makeTag(_name)
                << "and claptrap name: " << makeTag(ClapTrap::_name) << " !\n"
                << end;
}

std::ostream& DiamondTrap::announce(std::string color) {
  cout << color << "DiamondTrap " << std::left << std::setw(16)
       << makeTag(_name) << " " << color;
  return cout;
}