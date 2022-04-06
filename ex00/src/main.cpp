#include <iostream>
#include "ClapTrap.hpp"
#include "test.hpp"

using std::cout;

void test_orthodox() {
  test::header("Construcor and Destructor");
  {
    test::subject("unnamed");
    ClapTrap empty;
  }
  {
    test::subject("named");
    ClapTrap trap("trap");
  }
  {
    test::subject("copy");
    ClapTrap trap("trap");
    ClapTrap copy(trap);
  }
  {
    test::subject("assign");
    ClapTrap trap("trap");
    ClapTrap assign("before assign");
    assign = trap;
  }
}

void test_member_basic() {
  test::header("attack, takeDamage, beRepaired");
  ClapTrap trap("trap");
  test::subject("attack");
  trap.attack("barrel");
  test::subject("takeDamage");
  trap.takeDamage(5);
  test::subject("beRepaired");
  trap.beRepaired(3);
}

void test_member_cant() {
  {
    test::header("no hitpoints");
    ClapTrap trap("trap");
    trap.takeDamage(30);
    test::subject("can't attack");
    trap.attack("barrel");
    test::subject("can't be repaired");
    trap.beRepaired(10);
  }
  {
    test::header("no energy");
    ClapTrap trap("trap");
    for (uint i = 0; i < 10; ++i)
      trap.beRepaired(1);
    test::subject("can't attack");
    trap.attack("barrel");
    test::subject("can't be repaired");
    trap.beRepaired(10);
  }
}

int main(void) {
  test_orthodox();
  test_member_basic();
  test_member_cant();
}