#ifndef _MY_VECTOR_
#define _MY_VECTOR_

#include <iostream>
#include <stdexcept>
#include <cassert>

const size_t INITIAL_CAPACITY = 10;

class IntVector {
private:
	size_t count;
	size_t capacity;
	int* array;

	void cleanup();
	void copy(const IntVector& that);

public:
	IntVector();
	IntVector(const IntVector& that);
	IntVector& operator =(const IntVector& that);
	~IntVector();

	size_t size() const;
	bool isEmpty() const;
	int get(const size_t pos) const;
	void append(const int value);
	void insert(const size_t pos, const int value);
	void pop();
	void remove(const size_t pos);
	void set(const size_t pos, const int value);
	int find(const int value) const;
	void print(const IntVector&) const;

};


void IntVector::print(const IntVector& v) const {
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << v.get(i) << ' ';
	}
	std::cout << std::endl;
}

void IntVector::cleanup() {
	delete[] array;
}

void IntVector::copy(const IntVector& that) {
	count = that.count;
	capacity = that.capacity;
	array = new int[capacity];
	for (size_t i = 0; i < count; i++) {
		array[i] = that.array[i];
	}
}

IntVector::IntVector() : count{ 0 }, capacity{ INITIAL_CAPACITY } {
	array = new int[capacity];
}

IntVector::IntVector(const IntVector& that) {
	copy(that);
}

IntVector& IntVector::operator =(const IntVector& that) {
	if (this != &that) {
		cleanup();
		copy(that);
	}
	return *this;
}

IntVector::~IntVector() {
	cleanup();
}

size_t IntVector::size() const {
	return count;
}

bool IntVector::isEmpty() const {
	return size() == 0;
}

int IntVector::get(const size_t pos) const {
	if (pos >= count) {
		throw std::out_of_range("Trying to access element after the end!");
	}
	return array[pos];
}

void IntVector::append(const int value) {
	assert(count <= capacity);
	if (count == capacity) {
		int* newArray = new int[2 * capacity];
		capacity *= 2;
		for (size_t i = 0; i < count; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}

	array[count] = value;
	count++;
}

void IntVector::pop() {
	if (isEmpty()) {
		throw std::out_of_range("Trying to remove element from empty vector!");
	}
	count--;
}

void IntVector::insert(const size_t pos, const int value) {
	assert(count <= capacity);
	assert(pos <= count);
	if (count == capacity) {
		int* newArray = new int[2 * capacity];
		capacity *= 2;
		for (size_t i = 0; i < count; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}
	for (size_t i = count; i > pos; i--) {
		array[i] = array[i - 1];
	}
	array[pos] = value;
	count++;
}

void IntVector::remove(const size_t pos) {
	assert(pos <= count);
	for (size_t i = pos; i < count; i++) {
		array[i] = array[i + 1];
	}
	array[count] = 0;
	count--;
}

void IntVector::set(const size_t pos, const int value) {
	array[pos] = value;
}

int IntVector::find(const int value) const {
	for (size_t i = 0; i < count; i++) {
		if (get(i) == value) {
			return i;
		}
	}
	return -1;
}

#endif