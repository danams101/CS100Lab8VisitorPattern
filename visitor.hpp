#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include <string>

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
	virtual std::string getString() = 0;
};

class VisitMathML : public Visitor{
	private:
		std::string output = "";
		int index = 0;
	public:
		virtual void visit_op(Op* node){
			addIndex();
			std::string input = "\t<cn>" + node->stringify() + "</cn>\n";
			finaloutput(input);
		}
		virtual void visit_rand(Rand* node){
			addIndex();
			std::string input = "\t<cn>" + node->stringify() + "</cn>\n";
			finaloutput(input);
		}
		
		virtual void visit_add_begin(ADD* node){
			addIndex();
			std::string input = "\t<apply>\n";
			finaloutput(input);
			increment;
			addIndex();
			input = "\t<plus/>\n";
			finaloutput(input);
		}

        	virtual void visit_add_middle(ADD* node);
        	virtual void visit_add_end(ADD* node){
			decrement();
			addIndex();
			std::string input = "\t</apply>\n";
			finaloutput(input);
		}
		virtual void visit_sub_begin(SUB* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<minus/>\n";
                        finaloutput(input);
		}
        	virtual void visit_sub_middle(SUB* node);
        	virtual void visit_sub_end(SUB* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
		virtual void visit_mult_begin(Mult* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<times/>\n";
                        finaloutput(input);
		}
        	virtual void visit_mult_middle(Mult* node);
        	virtual void visit_mult_end(Mult* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
		virtual void visit_div_begin(Div* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<divide/>\n";
                        finaloutput(input);
		}
        	virtual void visit_div_middle(Div* node);
        	virtual void visit_div_end(Div* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}
        	virtual void visit_pow_begin(POW* node){
			addIndex();
                        std::string input = "\t<apply>\n";
                        finaloutput(input);
                        increment;
                        addIndex();
                        input = "\t<power/>\n";
                        finaloutput(input);
		}
        	virtual void visit_pow_middle(POW* node);
        	virtual void visit_pow_end(POW* node){
			decrement();
                        addIndex();
                        std::string input = "\t</apply>\n";
                        finaloutput(input);
		}

		virtual std::string getString(){
			return output;
		}
		std::string finaloutput(std::string input){
			return output = output + input;
		}
		void increment(){
			index++;
		}	
		void decrement(){
			index--;
		}
		void addIndex(){
			for(int i = 0; i < index; ++i){
				output = output + "\t";
			}
		}
};



#endif //__VISITOR_HPP__
