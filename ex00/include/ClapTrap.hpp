#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include "color.hpp"

using std::string;
typedef unsigned int uint;

namespace msg {

enum type {
  CLASSNAME,
  CONSTRUCTOR,
  DESTRUCTOR,
  ATTACK,
  SPECIAL,
  HITPOINT,
  ENERGY,
  REPAIR,
};

const string colorsOnType[] = {BLU, GRN, RED, YEL, CYN, MAG, MAG, YEL};
const string generalMsg[] = {"is out of hitpoints!", "is out of energy!",
                             "is repaired!"};

// const static string scavTrapMsg[4] = {"ScavTrap", "is scavvy!",
//                                       "is disintegrated!", "bonks"};
// const static string fragTrapMsg[4] = {"FragTrap", "is from frags!",
//                                       "is back to frags!", "throws frags"};
// const static string diamondTrapMsg[4] = {"diamondTrap", "is shiny!",
//                                          "is not shiny!", "zaps"};
}  // namespace msg

class ClapTrap {
 private:
  string _name;
  uint _hitPoints;
  uint _energyPoints;
  uint _attackDamage;

  enum { HITPOINTS = 10, ENERGY_POINTS = 10, ATTACK_DAMAGE = 0 };

 protected:
  // Util
  static string boldNum(int num);
  virtual const string& getLog(msg::type type) const;
  std::ostream& log(msg::type type) const;
  void logln(msg::type type) const;

 public:
  // Constructors & Destructor
  ClapTrap();
  ClapTrap(const ClapTrap& copy);
  ClapTrap(const string& name);

  // Destructor
  ~ClapTrap();

  // Operators
  ClapTrap& operator=(const ClapTrap& assign);

  // Methods
  void attack(string const& target);
  void takeDamage(uint amount);
  void beRepaired(uint amount);

  // Getters/Setters
  const string& getName() const;
  uint getHitPoints() const;
  uint getEnergyPoints() const;
  uint getAttackDamage() const;

  void setName(const string& name);
  void setHitPoints(uint hitPoints);
  void setEnergyPoints(uint energyPoints);
  void setAttackDamage(uint attackDamage);
};

#endif