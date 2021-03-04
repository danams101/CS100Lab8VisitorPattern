#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(ADD* node) = 0;
        virtual void visit_add_middle(ADD* node) = 0;
        virtual void visit_add_end(ADD* node) = 0;
        virtual void visit_sub_begin(SUB* node) = 0;
        virtual void visit_sub_middle(SUB* node) = 0;
        virtual void visit_sub_end(SUB* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(POW* node) = 0;
        virtual void visit_pow_middle(POW* node) = 0;
        virtual void visit_pow_end(POW* node) = 0;
};

#endif //__VISITOR_HPP__
