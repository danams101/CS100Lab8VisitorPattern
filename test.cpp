#include "add.hpp"
#include "op.hpp"
#include "base.hpp"
#include "iterator.hpp"

#include "gtest/gtest.h"


TEST(AddTest, getNumChildrenAndChild){
	Base* val1 = new Op(1.0);
	Base* val2 = new Op(2.0);

	Base* add = new Add(val1, val2);

	EXPECT_EQ(add->number_of_children(), 2);
	EXPECT_EQ(add->get_child(0), val1);
	EXPECT_EQ(add->get_child(1), val2);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
