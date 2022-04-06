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
  ~ClapTrap();

  // Operators
  ClapTrap& operator=(const ClapTrap& assign);

  // Functions
  void attack(std::string const& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  // Getters
  unsigned int getHitPoints() const;
  unsigned int getEnergyPoints() const;
  unsigned int getAttackDamage() const;

 private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

  // Util
  static std::string boldNum(int num);
  std::ostream& announce(const std::string& color = GRN);
};

#endif