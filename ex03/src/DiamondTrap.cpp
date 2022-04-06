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
  announce() << "is shiny!!!!\n" END;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap() {
  _name = name;
  FragTrap::_hitPoints = 100;
  ScavTrap::_energyPoints = 50;
  FragTrap::_attackDamage = 30;
  announce() << "is shiny!!!!\n" END;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy) {}

// Destructor
DiamondTrap::~DiamondTrap() { announce(RED) << "is no longer shiny!!!!\n" END; }

// Operators
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& assign) {
  ClapTrap::operator=(assign);
  DiamondTrap::_name = assign.DiamondTrap::_name;
  return *this;
}

void DiamondTrap::attack(std::string const& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  announce(RED) << "My private name: " BOLD << _name << YEL
                << " and claptrap name: " << ClapTrap::_name << " !\n" END;
}

std::ostream& DiamondTrap::announce(const std::string& color) {
  cout << color << "DiamondTrap " BOLD << std::left << _name << " " << color;
  return cout;
}
