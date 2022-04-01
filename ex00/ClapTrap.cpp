#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

using std::cout;
static std::string boldNum(int num);

// Constructors
ClapTrap::ClapTrap()
    : _name("(VOID)"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  announce(green) << "is born!\n" << end;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  announce(green) << "is born!\n" << end;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name),
      _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints),
      _attackDamage(copy._attackDamage) {
  announce(green) << "is copied!\n" << end;
}

// Destructor
ClapTrap::~ClapTrap() {
  announce(red) << "is dead!\n" << end;
}

// Operators
ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
  if (this != &assign) {
    announce(yellow) << "is assigned to " << makeTag(assign._name) << yellow
                     << "!\n"
                     << end;
    _name = assign._name;
    _hitPoints = assign._hitPoints;
    _energyPoints = assign._energyPoints;
    _attackDamage = assign._attackDamage;
  }

  return *this;
}

void ClapTrap::attack(std::string const& target) {
  if (_energyPoints > 0) {
    _energyPoints--;
    announce(yellow) << "attack " << makeTag(target) << yellow << ", causing "
                     << red << boldNum(_attackDamage) << yellow
                     << " points of damage!\n"
                     << end;
  } else {
    announce(red) << "is out of energy to attack!\n" << end;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints = _hitPoints > amount ? _hitPoints - amount : 0;
  announce(red) << "take " << boldNum(amount) << red << " points of damage!\n"
                << end;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints > 0) {
    _energyPoints--;
    _hitPoints += amount;
    announce(green) << "is repaired by " << boldNum(amount) << green
                    << " points!\n"
                    << end;
  } else {
    announce(red) << "is out of energy to repair!\n" << end;
  }
}

// Util
static std::string boldNum(int num) {
  std::stringstream ss;

  ss << bold << num << end;
  return ss.str();
}

std::string ClapTrap::makeTag(const std::string& str) {
  std::stringstream ss;

  ss << bold << "<" << str << ">" << end;
  return ss.str();
}

std::ostream& ClapTrap::announce(const std::string& color) {
  cout << color << "ClapTrap " << std::left << std::setw(16) << makeTag(_name)
       << " " << color;
  return cout;
}
