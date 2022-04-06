#include "ScavTrap.hpp"
#include <iomanip>
#include <iostream>
#include "color.hpp"

using std::cout;

// Constructors
ScavTrap::ScavTrap() : ClapTrap("(VOID)") {
  _hitPoints = HITPOINTS;
  _energyPoints = ENERGY_POINTS;
  _attackDamage = ATTACK_DAMAGE;
  announce() << "long for COMBAT!!!!!\n" END;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = HITPOINTS;
  _energyPoints = ENERGY_POINTS;
  _attackDamage = ATTACK_DAMAGE;
  announce() << "long for COMBAT!!!!!\n" END;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {}

// Destructor
ScavTrap::~ScavTrap() {
  announce(RED) << "is BLASTED into oblivion!!!!!\n" END;
}

// Operators
ScavTrap& ScavTrap::operator=(const ScavTrap& assign) {
  ClapTrap::operator=(assign);
  return *this;
}

void ScavTrap::attack(std::string const& target) {
  if (_energyPoints == 0) {
    announce(RED) << "is out of energy!\n" END;
    return;
  } else if (_hitPoints == 0) {
    announce(RED) << "is out of hit points!\n" END;
    return;
  } else {
    _energyPoints--;
    announce(YEL) << "bonk!! " BOLD << target << YEL ", causing " RED
                  << boldNum(_attackDamage) << YEL
                  << " points of damage!!!\n" END;
  }
}

void ScavTrap::guardGate() { announce(YEL) << "entered GATE KEEPER MODE!!!\n"; }

std::ostream& ScavTrap::announce(const std::string& color) {
  cout << color << "ScavTrap " << std::left << BOLD << _name << " " << color;
  return cout;
}
