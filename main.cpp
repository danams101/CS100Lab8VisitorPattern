#include "visitor.hpp"
#include "iterator.hpp"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

#include <iostream>

std::string PrintLaTeX(Base* ptr){
    Iterator* it = new Iterator(ptr);

    VisitorLaTeX* v = new VisitorLaTeX();
	for(it; !it->is_done(); it->next()){
		it->current_node()->accept(v,it->current_index());
	}

    return v->getString();
}

int main() {
    Base* val1 = new Op(1);
    Base* val2 = new Op(2);
    Base* val3 = new Op(3);

    SUB* s1 = new SUB(val2, val1);
    Mult* m1 = new Mult(val3, val2);
    Div* d1 = new Div(m1, s1);

    POW* p1 = new POW(val2, val3);
    ADD* a1 = new ADD(val2, val3);
    SUB* s2 = new SUB(p1,a1);

    ADD* add = new ADD(d1, s2);

    std::cout << add->stringify() << " => \n LaTeX: ";

    std::cout << PrintLaTeX(add) << "\n";


    return 0;
}
