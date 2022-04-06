#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  enum { HITPOINTS = 100, ENERGY_POINTS = 50, ATTACK_DAMAGE = 20 };

  // Disabled Constructor
  ScavTrap();

 public:
  // Constructors
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& copy);

  // Destructor
  virtual ~ScavTrap();

  // Operators
  ScavTrap& operator=(const ScavTrap& assign);

  // Function
  void attack(std::string const& target);
  void guardGate();

  // Util
  std::ostream& announce(std::string color);
};

#endif