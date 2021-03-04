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


		std::string VisitorMathML::finaloutput(std::string input){
			return str = str + input;
		}
                void VisitorMathML::visit_op(Op* node) {
			addIndex();
                        std::string input = "\t<cn>" + node->stringify() + "</cn>\n";
                	finaloutput(input);
		}

		void VisitorMathML::visit_rand(Rand* node){
			addIndex();
			std::string input = "\t<cn>" + node->stringify() + "/<cn>\n";
                        finaloutput(input);
		}

		void VisitorMathML::visit_add_begin(ADD* node){
			addIndex();
			std::string input = "\t<apply>\n";
			finaloutput(input);
			increment();
			addIndex();
			input = "\t<plus/>\n";
			finaloutput(input);
                }
		void VisitorMathML::visit_add_middle(ADD* node){}
		void VisitorMathML::visit_add_end(ADD* node){
                        decrement();
			addIndex();
			std::string input =  "\t</apply>\n";
			finaloutput(input);
                }
		void VisitorMathML::visit_sub_begin(SUB* node){
                        addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment();
                        addIndex();
                        input = "\t<minus/>\n";
                        finaloutput(input);
                }
                void VisitorMathML::visit_sub_middle(SUB* node){}
                void VisitorMathML::visit_sub_end(SUB* node){
                        decrement();
                        addIndex();
                        std::string input =  "\t</apply>\n";
                        finaloutput(input);
                }

		void VisitorMathML::visit_mult_begin(Mult* node){
                        addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment();
                        addIndex();
                        input = "\t<times/>\n";
                        finaloutput(input);
                }
                void VisitorMathML::visit_mult_middle(Mult* node){}
                void VisitorMathML::visit_mult_end(Mult* node){
                        decrement();
                        addIndex();
                        std::string input =  "\t</apply>\n";
                        finaloutput(input);
                }
		void VisitorMathML::visit_div_begin(Div* node){
                        addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment();
                        addIndex();
                        input = "\t<times/>\n";
                        finaloutput(input);
                }
                void VisitorMathML::visit_div_middle(Div* node){}
                void VisitorMathML::visit_div_end(Div* node){
                        decrement();
                        addIndex();
                        std::string input =  "\t</apply>\n";
                        finaloutput(input);
                }

		 void VisitorMathML::visit_pow_begin(POW* node){
                        addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment();
                        addIndex();
                        input = "\t<times/>\n";
                        finaloutput(input);
                }
                void VisitorMathML::visit_pow_middle(POW* node){}
                void VisitorMathML::visit_pow_end(POW* node){
                        decrement();
                        addIndex();
                        std::string input =  "\t</apply>\n";
                        finaloutput(input);
                }

