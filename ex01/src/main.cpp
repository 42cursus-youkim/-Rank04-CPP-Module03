#include <iostream>
#include "ScavTrap.hpp"
#include "test.hpp"

using std::cout;

void test_orthodox() {
  test::header("Construcor and Destructor");
  {
    test::subject("unnamed");
    ScavTrap empty;
  }
  {
    test::subject("named");
    ScavTrap scav("scav");
  }
  {
    test::subject("copy");
    ScavTrap scav("scav");
    ScavTrap copy(scav);
  }
  {
    test::subject("assign");
    ScavTrap scav("scav");
    ScavTrap assign("before assign");
    assign = scav;
  }
}

void test_member_virtual() {
  test::header("virtual attack, takeDamage, beRepaired");
  ClapTrap* botPtr = new ScavTrap("scav");
  test::subject("virtual attack");
  botPtr->attack("barrel");
  test::subject("takeDamage");
  botPtr->takeDamage(5);
  test::subject("beRepaired");
  botPtr->beRepaired(3);
  test::subject("virtual destructor");
  delete botPtr;
}

void test_member_cant() {
  test::header("no hitpoints");
  ScavTrap scav("scav");
  scav.takeDamage(300);
  test::subject("can't attack");
  scav.attack("barrel");
  test::subject("can't be repaired");
  scav.beRepaired(10);
}

void test_guard_gate() {
  test::header("guard gate");
  ScavTrap scav("scav");
  scav.guardGate();
}

int main(void) {
  test_orthodox();
  test_member_virtual();
  test_member_cant();
  test_guard_gate();
}