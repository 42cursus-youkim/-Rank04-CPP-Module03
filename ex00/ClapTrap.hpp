#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
 public:
  // Constructors
  ClapTrap(const ClapTrap& copy);
  ClapTrap(const std::string& name);

  // Destructor
  ~ClapTrap();

  // Operators
  ClapTrap& operator=(const ClapTrap& assign);

  // Functions
  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

  // Disabled Constructor
  ClapTrap();

  // Util
  std::string makeTag(const std::string& str);
  std::ostream& announce(std::string color);
};

// Colors
const std::string red = "\e[0;31m";
const std::string green = "\e[0;32m";
const std::string yellow = "\e[0;33m";
const std::string end = "\e[0m";
const std::string bold = "\e[1m";

#endif