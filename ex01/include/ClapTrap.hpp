#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include "color.hpp"

class ClapTrap {
 public:
  // Constructors
  ClapTrap();
  ClapTrap(const ClapTrap& copy);
  ClapTrap(const std::string& name);

  // Destructor
  virtual ~ClapTrap();

  // Operators
  ClapTrap& operator=(const ClapTrap& assign);

  // Functions
  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

 protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

  // Util
  std::string boldNum(int num);
  std::string makeTag(const std::string& str);
  std::ostream& announce(std::string color = GRN);
};

#endif