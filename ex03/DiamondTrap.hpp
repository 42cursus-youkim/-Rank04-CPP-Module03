#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
 public:
  // Constructors
  DiamondTrap(const std::string& name);
  DiamondTrap(const DiamondTrap& copy);

  // Destructor
  ~DiamondTrap();

  // Operators
  DiamondTrap& operator=(const DiamondTrap& assign);

  // Function
  void attack(std::string const& target);
  void whoAmI();

  // Util
  std::ostream& announce(std::string color);

 private:
  // Disabled Constructor
  DiamondTrap();
};

#endif