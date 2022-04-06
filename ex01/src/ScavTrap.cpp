#include "ScavTrap.hpp"
#include <iomanip>
#include <iostream>
#include "color.hpp"
using std::cout;

namespace msg {
const string scavTrapMsg[5] = {"ScavTrap", "is here to guard!",
                               "is blasted and cannot guard!", "bonks",
                               "entered gatekeeping mode!"};
}  // namespace msg

// Disabled Constructor
ScavTrap::ScavTrap() {}

// Constructors
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
  setHitPoints(HITPOINTS);
  setEnergyPoints(ENERGY_POINTS);
  setAttackDamage(ATTACK_DAMAGE);
  log(msg::CONSTRUCTOR);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
  setHitPoints(copy.getHitPoints());
  setEnergyPoints(copy.getEnergyPoints());
  setAttackDamage(copy.getAttackDamage());
  log(msg::CONSTRUCTOR);
}

// Destructor
ScavTrap::~ScavTrap() { log(msg::DESTRUCTOR); }

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