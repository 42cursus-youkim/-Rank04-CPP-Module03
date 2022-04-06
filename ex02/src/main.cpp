#include <iostream>
#include "FragTrap.hpp"
#include "test.hpp"

using std::cout;

void test_orthodox() {
  test::header("Construcor and Destructor");
  {
    test::subject("unnamed");
    FragTrap empty;
  }
  {
    test::subject("named");
    FragTrap frag("frag");
  }
  {
    test::subject("copy");
    FragTrap frag("frag");
    FragTrap copy(frag);
  }
  {
    test::subject("assign");
    FragTrap frag("frag");
    FragTrap assign("before assign");
    assign = frag;
  }
}

void test_member_virtual() {
  test::header("virtual attack, takeDamage, beRepaired");
  ClapTrap* botPtr = new FragTrap("frag");
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
  FragTrap frag("frag");
  frag.takeDamage(300);
  test::subject("can't attack");
  frag.attack("barrel");
  test::subject("can't be repaired");
  frag.beRepaired(10);
}

void test_highfive() {
  test::header("high five guys!");
  FragTrap frag("frag");
  frag.highFivesGuys();
}

int main(void) {
  test_orthodox();
  test_member_virtual();
  test_member_cant();
  test_highfive();
}