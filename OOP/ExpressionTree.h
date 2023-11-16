#pragma once

template<typename T>
class Expression
{
	virtual T lval() const = 0;
	

};

class Literal {
	Expression* clone() const override {
		return new Literal(*this);
	}
};

