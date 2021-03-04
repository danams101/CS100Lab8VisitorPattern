#include "add.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include "visitor.hpp"

#include "gtest/gtest.h"
#include <string>

TEST(MethodAddTest, normalBehavior){
	Base* val1 = new Op(1);
	Base* val2 = new Op(2);

	Base* add = new ADD(val1, val2);

	EXPECT_EQ(add->number_of_children(), 2);
	EXPECT_EQ(add->get_child(0), val1);
	EXPECT_EQ(add->get_child(1), val2);
	EXPECT_EQ(add->stringify(), "(1.000000+2.000000)");
	EXPECT_EQ(add->evaluate(), 3);
}

TEST(MethodSubTest, normalBehavior){
        Base* val1 = new Op(4);
        Base* val2 = new Op(2);

        Base* sub = new SUB(val1, val2);

        EXPECT_EQ(sub->number_of_children(), 2);
        EXPECT_EQ(sub->get_child(0), val1);
        EXPECT_EQ(sub->get_child(1), val2);
        EXPECT_EQ(sub->stringify(), "(4.000000-2.000000)");
        EXPECT_EQ(sub->evaluate(), 2);

}
TEST(MethodPowTest, normalBehavior){
        Base* val1 = new Op(2);
        Base* val2 = new Op(2);

        Base* pow = new POW(val1, val2);

        EXPECT_EQ(pow->number_of_children(), 2);
        EXPECT_EQ(pow->get_child(0), val1);
        EXPECT_EQ(pow->get_child(1), val2);
        EXPECT_EQ(pow->stringify(), "(2.000000**2.000000)");
        EXPECT_EQ(pow->evaluate(), 4);

}
TEST(MethodMultTest, normalBehavior){
        Base* val1 = new Op(1);
        Base* val2 = new Op(2);

        Base* mult = new Mult(val1, val2);

        EXPECT_EQ(mult->number_of_children(), 2);
        EXPECT_EQ(mult->get_child(0), val1);
        EXPECT_EQ(mult->get_child(1), val2);
        EXPECT_EQ(mult->stringify(), "(1.000000*2.000000)");
        EXPECT_EQ(mult->evaluate(), 2);

}
TEST(MethodDivTest, normalBehavior){
        Base* val1 = new Op(8);
        Base* val2 = new Op(2);

        Base* div = new Div(val1, val2);

        EXPECT_EQ(div->number_of_children(), 2);
        EXPECT_EQ(div->get_child(0), val1);
        EXPECT_EQ(div->get_child(1), val2);
        EXPECT_EQ(div->stringify(), "(8.000000/2.000000)");
        EXPECT_EQ(div->evaluate(), 4);

}
TEST(ExpressionTree, normalBehavior){
        Base* val1 = new Op(1);
        Base* val2 = new Op(2);
        Base* val3 = new Op(3);
        Base* val4 = new Op(4);
        Base* val5 = new Op(5);
        Base* val6 = new Op(6);

	Base* add = new ADD(val1,val3);
	Base* sub = new SUB(val6, val5);
	Base* pow = new POW(val4,val2);
	Base* mult = new Mult(add, sub);
        Base* div = new Div(pow, mult);

        EXPECT_EQ(div->number_of_children(), 2);
        EXPECT_EQ(div->get_child(0), pow);
        EXPECT_EQ(div->get_child(1), mult);
        EXPECT_EQ(div->stringify(), "((4.000000**2.000000)/((1.000000+3.000000)*(6.000000-5.000000)))");
        EXPECT_EQ(div->evaluate(), 4);

}

TEST(IteratorTest, basicTests){
        Base* val1 = new Op(1);
        Base* val2 = new Op(2);

        Base* add = new ADD(val1, val2);

	Iterator* it = new Iterator(add);
	EXPECT_EQ(it->current_node(), add);
	EXPECT_EQ(it->current_index(), 0);
	EXPECT_EQ(it->is_done(), false);

	it->next();
        EXPECT_EQ(it->current_node(), val1);
        EXPECT_EQ(it->current_index(), 0);
        EXPECT_EQ(it->is_done(), false);

        it->next();
        EXPECT_EQ(it->current_node(), add);
        EXPECT_EQ(it->current_index(), 1);
        EXPECT_EQ(it->is_done(), false);

	it->next();
        EXPECT_EQ(it->current_node(), val2);
        EXPECT_EQ(it->current_index(), 0);
        EXPECT_EQ(it->is_done(), false);

	it->next();
	EXPECT_EQ(it->is_done(), false);
        EXPECT_EQ(it->current_node(), add);
        EXPECT_EQ(it->current_index(), 2);

	it->next();
	EXPECT_EQ(it->is_done(), true);

}
TEST(IteratorTest,stringifyTest){
        Base* val1 = new Op(1);
        Base* val2 = new Op(2);
        Base* val3 = new Op(3);
        Base* val4 = new Op(4);
        Base* val5 = new Op(5);
        Base* val6 = new Op(6);

        Base* add = new ADD(val1,val3);
        Base* sub = new SUB(val6, val5);
        Base* pow = new POW(val4,val2);
        Base* mult = new Mult(add, sub);
        Base* div = new Div(pow, mult);

	std::string str = "";
	Iterator* it = new Iterator(div);

	for(it; !it->is_done(); it->next()){
		str = it->current_node()->stringify();
	}

        EXPECT_EQ(str, "((4.000000**2.000000)/((1.000000+3.000000)*(6.000000-5.000000)))");

}
TEST(IteratorTest, evaluateTest){
        Base* val1 = new Op(1);
        Base* val2 = new Op(2);
        Base* val3 = new Op(3);
        Base* val4 = new Op(4);
        Base* val5 = new Op(5);
        Base* val6 = new Op(6);

        Base* add = new ADD(val1,val3);
        Base* sub = new SUB(val6, val5);
        Base* pow = new POW(val4,val2);
        Base* mult = new Mult(add, sub);
        Base* div = new Div(pow, mult);

        double eval = 0;
        Iterator* it = new Iterator(div);

        for(it; !it->is_done(); it->next()){
                eval = it->current_node()->evaluate();
        }

        EXPECT_EQ(eval, 4);


}

//VisitorLaTeX tests
TEST(LatexTest, addTest){
	Base* val1 = new Op(1);
	Base* val2 = new Op(2);

	ADD* add = new ADD(val1, val2);
	Iterator* it = new Iterator(add);

    	VisitorLaTeX* v = new VisitorLaTeX();
	for(it; !it->is_done(); it->next()){
		it->current_node()->accept(v,it->current_index());
	}

	EXPECT_EQ(v->getString(), "${({1.000000}+{2.000000})}$");
}
TEST(LatexTest, subTest){
        Base* val1 = new Op(8);
        Base* val2 = new Op(3);

        SUB* sub = new SUB(val1, val2);
        Iterator* it = new Iterator(sub);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({8.000000}-{3.000000})}$");
}
TEST(LatexTest, multTest){
        Base* val1 = new Op(3);
        Base* val2 = new Op(4);

        Mult* mult = new Mult(val1, val2);
        Iterator* it = new Iterator(mult);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({3.000000}\\cdot{4.000000})}$");
}
TEST(LatexTest, divTest){
        Base* val1 = new Op(12);
        Base* val2 = new Op(6);

        Div* div = new Div(val1, val2);
        Iterator* it = new Iterator(div);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${\\frac{12.000000}{6.000000}}$");
}
TEST(LatexTest, powTest){
        Base* val1 = new Op(3);
        Base* val2 = new Op(2);

        POW* pow = new POW(val1, val2);
        Iterator* it = new Iterator(pow);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({3.000000}^{2.000000})}$");
}
TEST(LatexTest, treeTest){
        Base* val1 = new Op(1);
    	Base* val2 = new Op(2);
    	Base* val3 = new Op(3);

    	SUB* s1 = new SUB(val2, val1);
    	Mult* m1 = new Mult(val3, val2);
    	Div* d1 = new Div(m1, s1);

    	POW* p1 = new POW(val2, val3);

    	ADD* add = new ADD(d1, p1);
       
        Iterator* it = new Iterator(add);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({\\frac{({3.000000}\\cdot{2.000000})}{({2.000000}-{1.000000})}}+{({2.000000}^{3.000000})})}$");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
