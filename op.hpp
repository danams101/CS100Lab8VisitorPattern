#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { 
		val = value;
		num = 0; 
	}
        virtual double evaluate() { return val; }
        virtual std::string stringify() { return std::to_string(val); }
	virtual int number_of_children() {
		return num; 
	}
	virtual Base* get_child(int i) { return nullptr; }
	virtual void accept(Visitor* visitor, int index){
		visitor->visit_op(this);
	}

    private:
        double val;
	int num;
};

#endif //__OP_HPP__
