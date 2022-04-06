#include <iostream>
#include "DiamondTrap.hpp"
#include "test.hpp"

using std::cout;

void test_orthodox() {
  test::header("Construcor and Destructor");
  {
    test::subject("unnamed");
    DiamondTrap empty;
    TEST_EXPECT(empty.getHitPoints() == 100 and
                empty.getEnergyPoints() == 50 and
                empty.getAttackDamage() == 30);
  }
  {
    test::subject("named");
    DiamondTrap dia("dia");
  }
  {
    test::subject("copy");
    DiamondTrap dia("dia");
    DiamondTrap copy(dia);
  }
  {
    test::subject("assign");
    DiamondTrap dia("dia");
    DiamondTrap assign("before assign");
    assign = dia;
  }
}

void test_member_virtual() {
  test::header("virtual attack, takeDamage, beRepaired");
  ClapTrap* botPtr = new DiamondTrap("dia");
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
  DiamondTrap dia("dia");
  dia.takeDamage(300);
  test::subject("can't attack");
  dia.attack("barrel");
  test::subject("can't be repaired");
  dia.beRepaired(10);
}

void test_special() {
  test::header("both special");
  DiamondTrap dia("dia");
  test::subject("high five guys!");
  dia.highFivesGuys();
  test::subject("gate guard");
  dia.guardGate();
  test::subject("whoami");
  dia.whoAmI();
}

int main(void) {
  test_orthodox();
  test_member_virtual();
  test_member_cant();
  test_special();
}