#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <string>

class Op;
class Rand;
class ADD;
class SUB;
class Mult;
class Div;
class POW;

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

class VisitorLaTeX : public Visitor {
    private:
	std::string str;
	
	
    public:
	VisitorLaTeX();

	std::string getString();
        virtual void visit_op(Op* node);
        virtual void visit_rand(Rand* node);

	virtual void visit_add_begin(ADD* node);
        virtual void visit_add_middle(ADD* node);
        virtual void visit_add_end(ADD* node);
        virtual void visit_sub_begin(SUB* node);
        virtual void visit_sub_middle(SUB* node);
        virtual void visit_sub_end(SUB* node);
        virtual void visit_mult_begin(Mult* node);
        virtual void visit_mult_middle(Mult* node);
        virtual void visit_mult_end(Mult* node);
        virtual void visit_div_begin(Div* node);
        virtual void visit_div_middle(Div* node);
        virtual void visit_div_end(Div* node);
        virtual void visit_pow_begin(POW* node);
        virtual void visit_pow_middle(POW* node);
        virtual void visit_pow_end(POW* node);
};

class VisitorMathML : public Visitor {
	private:
		std::string output = "";
		int indent = 0;
	public:

		virtual void visit_op(Op* node);
		virtual void visit_rand(Rand* node);
		
		virtual void visit_add_begin(ADD* node);
        	virtual void visit_add_middle(ADD* node);
        	virtual void visit_add_end(ADD* node);
		virtual void visit_sub_begin(SUB* node);
        	virtual void visit_sub_middle(SUB* node);
        	virtual void visit_sub_end(SUB* node);
		virtual void visit_mult_begin(Mult* node);
        	virtual void visit_mult_middle(Mult* node);
        	virtual void visit_mult_end(Mult* node);
		virtual void visit_div_begin(Div* node);
        	virtual void visit_div_middle(Div* node);
        	virtual void visit_div_end(Div* node);
        	virtual void visit_pow_begin(POW* node);
        	virtual void visit_pow_middle(POW* node);
        	virtual void visit_pow_end(POW* node);
		virtual std::string getString(){
			return output;
		}
		std::string finalstring(std::string input);
		void increment(){
			indent = indent + 1;
		}
		void decrement(){
			indent = indent - 1;
		}
		void addIndent(){
			for(int i = 0; i < indent; ++i){
				output = output + "\t";
			}
		
		}
};


#endif //__VISITOR_HPP__
