#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include "color.hpp"

using std::string;
typedef unsigned int uint;

namespace msg {

enum type {
  /* specific msg */
  CLASSNAME,
  CONSTRUCTOR,
  DESTRUCTOR,
  ATTACK,
  SPECIAL,
  /* general msg */
  LOW_HITPOINT,
  LOW_ENERGY,
  REPAIR,
  TAKE_DAMAGE,
};

const string colorsOnType[] = {BLU, GRN, RED, YEL, CYN, MAG, MAG, YEL, RED};
const string generalMsg[] = {"is out of hitpoints!", "is out of energy!",
                             "is repaired by", "is damaged by"};

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
  void attack(const string& target);
  void takeDamage(uint amount);
  void beRepaired(uint amount);

  // Getters/Setters
 public:
  const string& getName() const;
  uint getHitPoints() const;
  uint getEnergyPoints() const;
  uint getAttackDamage() const;

  void setName(const string& name);
  void setHitPoints(uint hitPoints);
  void setEnergyPoints(uint energyPoints);
  void setAttackDamage(uint attackDamage);

  // Logger
 private:
  virtual const string& getLog(msg::type type) const;
  static string boldNum(int num);
  std::ostream& logInternal(msg::type type) const;
  std::ostream& log_internal(msg::type type, int amount) const;

 protected:
  virtual void log(msg::type type) const;
  virtual void log(msg::type type, int num) const;
  virtual void log(msg::type type, const string& msg, int num) const;
};

#endif