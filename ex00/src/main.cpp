#include <iostream>
#include "ClapTrap.hpp"
#include "test.hpp"

using std::cout;

void test_orthodox() {
  test::header("Construcor and Destructor");
  {
    test::subject("empty name");
    ClapTrap trap;
    TEST_EXPECT(trap.getHitPoints() == 10 and trap.getEnergyPoints() == 10 and
                trap.getAttackDamage() == 0);
  }
  {
    test::subject("copy");
    ClapTrap trap("trap");
    ClapTrap copy(trap);
  }
  {
    test::subject("assign");
    ClapTrap trap("trap");
    ClapTrap assign;
    assign = trap;
  }
}

void test_member_basic() {
  test::header("attack, takeDamage, beRepaired");
  ClapTrap trap("trap");
  trap.attack("barrel");
  trap.takeDamage(5);
  TEST_EXPECT(trap.getHitPoints() == 5);
  trap.beRepaired(3);
  TEST_EXPECT(trap.getHitPoints() == 8);
}

void test_member_cant() {
  {
    test::header("no hitpoints");
    ClapTrap trap("trap");
    trap.takeDamage(30);
    TEST_EXPECT(trap.getHitPoints() == 0);
    test::subject("can't attack");
    trap.attack("barrel");
    test::subject("can't be repaired");
    trap.beRepaired(10);
  }
  {
    test::header("no energy");
    ClapTrap trap("trap");
    trap.setEnergyPoints(0);
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