#ifndef __VISITMATHML_HPP__
#define __VISITMATHML_HPP__

#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "visitor.hpp"

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class VisitMathML : public Visitor{
	private:
	std::string start = "<math>\n";
	std::string end = "</math>\n";
	std::string str;

	public:
	void VisitMathML::output(std::string input){
		str = str + input;
	}

	void VisitMathML::visit_op(Op* node){
		std::string input = "		<cn>" + node->stringify() + "</cn>";
		output(input);
	}
	
	void VisitMathML::visit_add_begin_M(ADD* node){
		std::string input = "	<apply>\n";
		output(input);
	}

	void VisitMathML::visit_add_middle_M(ADD* node){
		std::string input = "		<plus/>\n";
	}

	void VisitMathML::visit_add_end_M(ADD* node){
		std::string input = "	</apply>\n";
	}
	
}

#endif //VISITMATHML_HPP
