#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
 public:
  // Constructors
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
  std::ostream& announce(std::string color);

 private:
  // Disabled Constructor
  ScavTrap();
};

#endif