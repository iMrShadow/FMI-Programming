#include <iostream>

template<typename T>
class Expression
{
public:
	virtual T eval() const = 0;
	virtual Expression<T>* clone() const = 0;
	virtual void print(std::ostream& out) const = 0;
	virtual ~Expression() {}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Expression<T>& expr) {
	expr.print(out);
	return out;
}

template<typename T>
class Literal : public Expression<T> {

private:
	const T value;
public:
	Literal(const T& value) : value(value) {}

	Expression<T>* clone() const override {
		return new Literal(value);
	}
	T eval() const override {
		return value;
	}

	void print(std::ostream& out) const override {
		out << value;
	}
};

template<typename T>
class Add : public Expression<T> {
private:
	Expression<T>* left;
	Expression<T>* right;

public:

	Add(const Expression<T>& left, const Expression<T>& right) : left(left.clone()), right(right.clone()) {}

	Add(const Expression<T>* left, const Expression<T>* right) : Add(*left, *right) {}

	Expression<T>* clone() {
		return new Add(left, right);
	}

	T eval() const override {
		return left->eval() + right->eval();
	}
	void print(std::ostream& out) {
		left->print(out);
		out << " + ";
		right->print(out);
	}

	~Add() {
		delete left;
		delete right;
	}
};

template<typename T>
class Mul : public Expression<T> {
private:
	Expression<T>* left;
	Expression<T>* right;

public:
	Mul(const Expression<T>& left, const Expression<T>& right) : left(left.clone()), right(right.clone()) {}

	Mul(const Expression<T>* left, const Expression<T>* right) : Mul(*left, *right) {}

	Expression<T>* clone() {
		return new Mul(left->clone(), right->clone());
	}

	T eval() const override{
		return left->clone() * right->clone();
	}

	void print(std::ostream& out) {
		left->print(out);
		out << " * ";
		right->print(out);
	}

	~Mul() {
		delete left;
		delete right;
	}
};


template<typename T>
class Sub : public Expression<T> {
private:
	Expression<T>* left;
	Expression<T>* right;

public:
	Sub(const Expression<T>& left, const Expression<T>& right) : left(left.clone()), right(right.clone()) {}

	Sub(const Expression<T>* left, const Expression<T>* right) : Sub(*left, *right) {}

	Expression<T>* clone() {
		new Add(left->clone(), right->clone());
	}

	T eval() const override{
		return left->clone() - right->clone();
	}
};

template<typename T>
class Div : public Expression<T> {
private:
	Expression<T>* left;
	Expression<T>* right;

public:
	Div(const Expression<T>& left, const Expression<T>& right) : left(left.clone()), right(right.clone()) {}

	Div(const Expression<T>* left, const Expression<T>* right) : Div(*left, *right) {}

	Expression<T>* clone() {
		new Add(left->clone(), right->clone());
	}

	T eval() const override{
		return left->clone() / right->clone();
	}
};


template<typename T>
class Pow : public Expression<T> {
private:
	Expression<T>* left;
	Expression<T>* right;

public:
	Pow(const Expression<T>& left, const Expression<T>& right) : left(left.clone()), right(right.clone()) {}

	Pow(const Expression<T>* left, const Expression<T>* right) : Pow(*left, *right) {}

	Expression<T>* clone() {
		new Add(left->clone(), right->clone());
	}

	T eval() const override{
		return left->clone() + right->clone();
	}
};

int main() {
	Expression<int>* ef = new Mul(
		Add(Literal(5), Literal(4)),
		Sub(Literal(2), Literal(3))
	);
	//Literal f(4);
	return 0;
}



