#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include "color.hpp"

using std::cout;

namespace msg {

const string clapTrapMsg[4] = {"ClapTrap", "is born!", "is dead!", "attacks"};

}  // namespace msg

// Constructors
ClapTrap::ClapTrap()
    : _name("(VOID)"),
      _hitPoints(HITPOINTS),
      _energyPoints(ENERGY_POINTS),
      _attackDamage(ATTACK_DAMAGE) {
  logln(msg::CONSTRUCTOR);
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _hitPoints(HITPOINTS),
      _energyPoints(ENERGY_POINTS),
      _attackDamage(ATTACK_DAMAGE) {
  logln(msg::CONSTRUCTOR);
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name),
      _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints),
      _attackDamage(copy._attackDamage) {
  logln(msg::CONSTRUCTOR);
}

// Destructor
ClapTrap::~ClapTrap() { logln(msg::DESTRUCTOR); }

// Operators
ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
  if (this != &assign) {
    setName(assign.getName());
    setHitPoints(assign.getHitPoints());
    setEnergyPoints(assign.getEnergyPoints());
    setAttackDamage(assign.getAttackDamage());
  }

  return *this;
}

// Util
string ClapTrap::boldNum(int num) {
  std::stringstream ss;

  ss << BOLD << num << END;
  return ss.str();
}

const string& ClapTrap::getLog(msg::type type) const {
  return msg::clapTrapMsg[type];
}

std::ostream& ClapTrap::log(msg::type type) const {
  cout << msg::colorsOnType[type] << getLog(msg::CLASSNAME) << " " << getName()
       << " ";
  if (type > msg::SPECIAL)
    cout << msg::generalMsg[type - msg::SPECIAL - 1] << " ";
  else
    cout << getLog(type) << " ";
  return cout;
}

void ClapTrap::logln(msg::type type) const { log(type) << "\n"; }

// Methods
void ClapTrap::attack(std::string const& target) {
  if (_energyPoints == 0)
    return logln(msg::ENERGY);
  else if (_hitPoints == 0)
    return logln(msg::HITPOINT);
  else {
    _energyPoints--;
    log(msg::ATTACK) << target << "for " << boldNum(_attackDamage)
                     << YEL " points!\n" END;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints = _hitPoints > amount ? _hitPoints - amount : 0;
  cout << RED << getLog(msg::CLASSNAME) << " take " << boldNum(amount)
       << RED " points of damage!\n" END;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints > 0) {
    _energyPoints--;
    _hitPoints += amount;
    // announce() << "is repaired by " << boldNum(amount) << GRN
    //            << " points!\n" END;
  } else {
    // announce(RED) << "is out of energy to repair!\n" END;
  }
}

// Getters/Setters
const string& ClapTrap::getName() const { return _name; }
uint ClapTrap::getHitPoints() const { return _hitPoints; }
uint ClapTrap::getEnergyPoints() const { return _energyPoints; }
uint ClapTrap::getAttackDamage() const { return _attackDamage; }

void ClapTrap::setName(const string& name) { _name = name; }
void ClapTrap::setHitPoints(uint hitPoints) { _hitPoints = hitPoints; }
void ClapTrap::setEnergyPoints(uint energyPoints) {
  _energyPoints = energyPoints;
}
void ClapTrap::setAttackDamage(uint attackDamage) {
  _attackDamage = attackDamage;
}
