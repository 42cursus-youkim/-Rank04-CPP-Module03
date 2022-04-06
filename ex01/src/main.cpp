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

void test_member_basic() {
  test::header("attack, takeDamage, beRepaired");
  ScavTrap scav("scav");
  test::subject("attack");
  scav.attack("barrel");
  test::subject("takeDamage");
  scav.takeDamage(5);
  test::subject("beRepaired");
  scav.beRepaired(3);
}

void test_member_cant() {
  {
    test::header("no hitpoints");
    ScavTrap scav("scav");
    scav.takeDamage(300);
    test::subject("can't attack");
    scav.attack("barrel");
    test::subject("can't be repaired");
    scav.beRepaired(10);
  }
  {
    test::header("no energy");
    ScavTrap scav("scav");
    for (uint i = 0; i < 50; ++i)
      scav.beRepaired(1);
    test::subject("can't attack");
    scav.attack("barrel");
    test::subject("can't be repaired");
    scav.beRepaired(10);
  }
}

void test_guard_gate() {
  test::header("guard gate");
  ScavTrap scav("scav");
  scav.guardGate();
}
 
int main(void) {
  test_orthodox();
  test_member_basic();
  test_member_cant();
  test_guard_gate();
}