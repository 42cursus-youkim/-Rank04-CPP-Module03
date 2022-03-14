#include "ClapTrap.hpp"
#include <iostream>

using std::cout;
// Constructors
ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name),
      _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints),
      _attackDamage(copy._attackDamage) {}

// Destructor
ClapTrap::~ClapTrap() {
  cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

// Operators
ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
  _name = assign._name;
  return *this;
}

void ClapTrap::attack(std::string const& target) {
  cout << "ClapTrap " << _name << " attack " << target << ", causing "
       << _attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints = _hitPoints > amount ? _hitPoints - amount : 0;
  cout << "ClapTrap " << _name << " take " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount) {
  _hitPoints += amount;
  cout << "ClapTrap " << _name << " is repaired by " << amount << " points!\n";
}
