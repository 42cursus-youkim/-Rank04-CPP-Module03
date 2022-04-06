#include <iostream>
#include "DiamondTrap.hpp"

using std::cout;

static void testDefault() { DiamondTrap dia("default"); }

static void testCopy() {
  DiamondTrap dia("base");
  DiamondTrap copiedDia = dia;
}

static void testAssign() {
  DiamondTrap dia("base");
  DiamondTrap assignedDia("before assign");

  assignedDia = dia;
}

static void testWork() {
  DiamondTrap dia("dia");
  dia.whoAmI();
  dia.attack("cheese");
  dia.takeDamage(10);
  dia.beRepaired(10);
  dia.guardGate();
  dia.highFivesGuys();
}

// static void testVirtual() {

// }

int main() {
  typedef void (*testFunc)(void);
  std::string names[] = {"testDefault", "testCopy", "testAssign", "testWork"};
  testFunc tests[] = {testDefault, testCopy, testAssign, testWork};
  for (int i = 0; i < 4; i++) {
    cout << "==== Running " << names[i] << " ====\n";
    tests[i]();
    cout << "==========================\n\n";
  }
}