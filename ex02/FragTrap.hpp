#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
 public:
  // Constructors
  FragTrap(const std::string& name);
  FragTrap(const FragTrap& copy);

  // Destructor
  ~FragTrap();

  // Operators
  FragTrap& operator=(const FragTrap& assign);

  // Function
  void attack(std::string const& target);
  void guardGate();

 private:
  // Disabled Constructor
  FragTrap();
};

#endif