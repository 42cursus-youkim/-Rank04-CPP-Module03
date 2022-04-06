#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
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
  log(msg::CONSTRUCTOR);
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _hitPoints(HITPOINTS),
      _energyPoints(ENERGY_POINTS),
      _attackDamage(ATTACK_DAMAGE) {
  log(msg::CONSTRUCTOR);
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name),
      _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints),
      _attackDamage(copy._attackDamage) {
  log(msg::CONSTRUCTOR);
}

// Destructor
ClapTrap::~ClapTrap() { log(msg::DESTRUCTOR); }

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

// Methods
void ClapTrap::attack(const string& target) {
  if (_energyPoints <= 0)
    log(msg::LOW_ENERGY);
  else if (_hitPoints <= 0)
    log(msg::LOW_HITPOINT);
  else {
    _energyPoints--;
    log(msg::ATTACK, target, _attackDamage);
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints = _hitPoints > amount ? _hitPoints - amount : 0;
  log(msg::TAKE_DAMAGE, amount);
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints <= 0)
    log(msg::LOW_ENERGY);
  else {
    _energyPoints--;
    _hitPoints += amount;
    log(msg::REPAIR, amount);
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

// Logger
string ClapTrap::boldNum(int num) {
  std::stringstream ss;

  ss << BOLD << num << END;
  return ss.str();
}

const string& ClapTrap::getLog(msg::type type) const {
  return msg::clapTrapMsg[type];  // Different per class
}

std::ostream& ClapTrap::logInternal(msg::type type) const {
  cout << msg::colorsOnType[type] << getLog(msg::CLASSNAME) << " " BOLD
       << getName() << msg::colorsOnType[type] << " ";
  if (type >= msg::LOW_HITPOINT)
    cout << msg::generalMsg[type - msg::LOW_HITPOINT];
  else
    cout << getLog(type);
  return cout;
}

void ClapTrap::log(msg::type type) const { logInternal(type) << "\n"; }

void ClapTrap::log(msg::type type, int num) const {
  logInternal(type) << " " << boldNum(num) << msg::colorsOnType[type]
                    << " points!\n";
}

void ClapTrap::log(msg::type type, const string& msg, int num) const {
  logInternal(type) << " " BOLD << msg::colorsOnType[type] << msg << " for "
                    << boldNum(num) << msg::colorsOnType[type] << " points!\n";
}
