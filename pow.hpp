#ifndef POW_HPP
#define POW_HPP

#include "base.hpp"
#include <cmath>
#include "visitor.hpp"
class POW : public Base{
	private:
		Base* val1 = nullptr;
		Base* val2 = nullptr;

	public:
		POW(Base* val1, Base* val2):Base(){
			this -> val1 = val1;
			this -> val2 = val2;
		}

		virtual double evaluate(){
			return (pow(val1->evaluate(),val2->evaluate()));
		}

		virtual std::string stringify() {
	   		 return ("(" + val1->stringify() + "**" + val2->stringify() + ")"); 
		}
                virtual int number_of_children() {
                        int num = 0;
                        if(val1!= nullptr)
                                ++num;
                        if(val2!= nullptr)
                                ++num;
                        return num;
                }

                virtual Base* get_child(int i) {
                        if(i < number_of_children()){
                                if(i == 0){
                                        return val1;
                                }
                                if(i == 1){
                                        return val2;
                                }
                        }

                }

		virtual void accept(Visitor* visitor, int index) {
                        if(index == 0)
                                visitor->visit_pow_begin(this);
                        if(index == 1)
                                visitor->visit_pow_middle(this);
                        if(index == 2)
                                visitor->visit_pow_end(this);
		}
};

#endif
