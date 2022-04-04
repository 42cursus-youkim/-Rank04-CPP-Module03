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
  void attack(std::string const& target);
  void highFivesGuys();

  // Util
  std::ostream& announce(std::string color);
};

#endif