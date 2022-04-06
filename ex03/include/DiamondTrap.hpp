#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
 public:
  // Constructors
  DiamondTrap();
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
  std::ostream& announce(const std::string& color = GRN);

 private:
  std::string _name;
};

#endif