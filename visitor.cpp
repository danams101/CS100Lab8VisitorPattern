#include "visitor.hpp"

#include "base.hpp"
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"

VisitorLaTeX::VisitorLaTeX() {
    str = "$";
}

std::string VisitorLaTeX::getString(){
    return str + "$";
}

void VisitorLaTeX::visit_op(Op* node){
    str += "{" + node->stringify() + "}";
}
void VisitorLaTeX::visit_rand(Rand* node){
    str += "{" + node->stringify() + "}";
}

void VisitorLaTeX::visit_add_begin(ADD* node){
    str += "{(";
}
void VisitorLaTeX::visit_add_middle(ADD* node){
    str += "+";
}
void VisitorLaTeX::visit_add_end(ADD* node){
    str += ")}";
}
void VisitorLaTeX::visit_sub_begin(SUB* node){
    str += "{(";
}
void VisitorLaTeX::visit_sub_middle(SUB* node){
    str += "-";
}
void VisitorLaTeX::visit_sub_end(SUB* node){
    str += ")}";
}
void VisitorLaTeX::visit_mult_begin(Mult* node){
    str += "{(";
}
void VisitorLaTeX::visit_mult_middle(Mult* node){
    str += "\\cdot";
}
void VisitorLaTeX::visit_mult_end(Mult* node){
    str += ")}";
}
void VisitorLaTeX::visit_div_begin(Div* node){
    str += "{\\frac";
}
void VisitorLaTeX::visit_div_middle(Div* node){
    str += "";
}
void VisitorLaTeX::visit_div_end(Div* node){
    str += "}";
}
void VisitorLaTeX::visit_pow_begin(POW* node){
    str += "{(";
}
void VisitorLaTeX::visit_pow_middle(POW* node){
    str += "^";
}
void VisitorLaTeX::visit_pow_end(POW* node){
    str += ")}";
}

