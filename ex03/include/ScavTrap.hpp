#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  // Constructors
  ScavTrap();
  ScavTrap(const std::string& name);
  ScavTrap(const ScavTrap& copy);

  // Destructor
  ~ScavTrap();

  // Operators
  ScavTrap& operator=(const ScavTrap& assign);

  // Function
  void attack(std::string const& target);
  void guardGate();

  // Util
  std::ostream& announce(const std::string& color = GRN);

 protected:
  enum { HITPOINTS = 100, ENERGY_POINTS = 50, ATTACK_DAMAGE = 20 };
};

#endif