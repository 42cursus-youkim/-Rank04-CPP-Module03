#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  announce(green) << "long for COMBAT!!!!!\n" << end;
}

// TODO: copy constructor
// ScavTrap::ScavTrap(const ScavTrap& copy) {
//   (void)copy;
// }

// Destructor
ScavTrap::~ScavTrap() {
  announce(red) << "is BLASTED into oblivion!!!!!\n" << end;
}

// Operators
ScavTrap& ScavTrap::operator=(const ScavTrap& assign) {
  if (this != &assign) {
    announce(yellow) << "is assigned to " << makeTag(assign._name) << yellow
                     << "!!!!!\n"
                     << end;
    _name = assign._name;
    _hitPoints = assign._hitPoints;
    _energyPoints = assign._energyPoints;
    _attackDamage = assign._attackDamage;
  }
  return *this;
}

void ScavTrap::attack(std::string const& target) {
  announce(yellow) << "attack " << makeTag(target) << yellow << ", causing "
                   << red << boldNum(_attackDamage) << yellow
                   << " points of DAMAGE! (and that was a lot)\n"
                   << end;
}
