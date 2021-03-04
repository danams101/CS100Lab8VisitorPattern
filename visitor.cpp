#include "visitor.hpp"

#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "pow.hpp"
#include <string>

		virtual void VisitMathML::visit_op(Op* node){
			addIndex();
			std::string input = "\t<cn>" + node->stringify() + "</cn>\n";
			finaloutput(input);
		}
		virtual void VisitMathML::visit_rand(Rand* node){
			addIndex();
			std::string input = "\t<cn>" + node->stringify() + "</cn>\n";
			finaloutput(input);
		}
		
		virtual void VisitMathML::visit_add_begin(ADD* node){
			addIndex();
			std::string input = "\t<apply>\n";
			finaloutput(input);
			increment;
			addIndex();
			input = "\t<plus/>\n";
			finaloutput(input);
		}

        	virtual void VisitMathML::visit_add_middle(ADD* node);
        	virtual void VisitMathML::visit_add_end(ADD* node){
			decrement();
			addIndex();
			std::string input = "\t</apply>\n";
			finaloutput(input);
		}
		virtual void VisitMathML::visit_sub_begin(SUB* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<minus/>\n";
                        finaloutput(input);
		}
        	virtual void VisitMathML::visit_sub_middle(SUB* node);
        	virtual void VisitMathML::visit_sub_end(SUB* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
		virtual void VisitMathML::visit_mult_begin(Mult* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<times/>\n";
                        finaloutput(input);
		}
        	virtual void VisitMathML::visit_mult_middle(Mult* node);
        	virtual void VisitMathML::visit_mult_end(Mult* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
		virtual void VisitMathML::visit_div_begin(Div* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<divide/>\n";
                        finaloutput(input);
		}
        	virtual void VisitMathML::visit_div_middle(Div* node);
        	virtual void VisitMathML::visit_div_end(Div* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
        	virtual void VisitMathML::visit_pow_begin(POW* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<power/>\n";
                        finaloutput(input);
		}
        	virtual void VisitMathML::visit_pow_middle(POW* node);
        	virtual void VisitMathML::visit_pow_end(POW* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
