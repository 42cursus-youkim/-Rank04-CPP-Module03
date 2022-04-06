#include "ClapTrap.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>
#include "color.hpp"

using std::cout;
static std::string boldNum(int num);

// Constructors
ClapTrap::ClapTrap()
    : _name("(VOID)"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  announce() << "is born!\n" END;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  announce() << "is born!\n" END;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name),
      _hitPoints(copy._hitPoints),
      _energyPoints(copy._energyPoints),
      _attackDamage(copy._attackDamage) {
  announce() << "is copied!\n" END;
}

// Destructor
ClapTrap::~ClapTrap() { announce(RED) << "is dead!\n" END; }

// Operators
ClapTrap& ClapTrap::operator=(const ClapTrap& assign) {
  if (this != &assign) {
    announce(YEL) << "is assigned to " BOLD << assign._name << YEL << "!\n" END;
    _name = assign._name;
    _hitPoints = assign._hitPoints;
    _energyPoints = assign._energyPoints;
    _attackDamage = assign._attackDamage;
  }

  return *this;
}

void ClapTrap::attack(std::string const& target) {
  if (_energyPoints == 0) {
    announce(RED) << "is out of energy!\n" END;
    return;
  } else if (_hitPoints == 0) {
    announce(RED) << "is out of hit points!\n" END;
    return;
  } else {
    _energyPoints--;
    announce(YEL) << "attack " BOLD << target << YEL ", causing " RED
                  << boldNum(_attackDamage) << YEL
                  << " points of damage!\n" END;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints = _hitPoints > amount ? _hitPoints - amount : 0;
  announce(RED) << "take " << boldNum(amount) << RED " points of damage!\n" END;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_energyPoints == 0) {
    announce(RED) << "is out of energy to repair!\n" END;
  } else if (_hitPoints == 0) {
    announce(RED) << "is out of hit points to repair!\n" END;
  } else {
    _energyPoints--;
    _hitPoints += amount;
    announce() << "is repaired by " << boldNum(amount) << GRN
               << " points!\n" END;
  }
}

// Util
static std::string boldNum(int num) {
  std::stringstream ss;

  ss << BOLD << num << END;
  return ss.str();
}

std::ostream& ClapTrap::announce(const std::string& color) {
  cout << color << "ClapTrap " << std::left << BOLD << _name << " " << color;
  return cout;
}
