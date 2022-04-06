#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
 public:
  // Constructors
  FragTrap();
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& copy);

  // Destructor
  ~FragTrap();

  // Operators
  FragTrap& operator=(const FragTrap& assign);

  // Function
  void highFivesGuys();

  // Util
  std::ostream& announce(const std::string& color = GRN);

 protected:
  enum { HITPOINTS = 100, ENERGY_POINTS = 100, ATTACK_DAMAGE = 30 };
};

#endif