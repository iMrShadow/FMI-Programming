#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const size_t INITIAL_CAPACITY = 10;

class IntVector {
private:
	size_t capacity;
	size_t count;
	int* array;

	void cleanup() {
		delete[] array;
	}
	void copy(const IntVector& that) {
		count = that.count;
		capacity = that.capacity;
		array = new int[capacity];
		for (size_t i = 0; i < capacity; i++) {
			array[i] = that.array[i];
		}
	}
public:
	IntVector() : count(0), capacity(INITIAL_CAPACITY), array(new int[10]) {} //default con

	IntVector(const IntVector& that) {
		capacity = that.capacity;
		count = that.count;
		array = new int[capacity];
		for (size_t i = 0; i < count; i++) {
			array[i] = that.array[i];
		}
	}

	IntVector& operator =(const IntVector& that) { //assignment
		if (this != &that) {
			cleanup();
			copy(that);
		}
		return *this;
	}


	IntVector& operator= (IntVector& that) {
		return *this;
	}

	~IntVector() {
		cleanup();
	} //decon

	size_t size() const{
		return count;
	}

	int get(const size_t pos) const {
		if(pos >=count){
			throw std::out_of_range("Trying to access element after the end!");
		}
		return array[pos];
	}

	void append(int value) {
		if (count >= capacity) {
			resize();
		}

	}

	void insert(int pos, int value) {

	}

	void resize() {

	}

};

void print(const IntVector& v) {
	size_t size = v.size();
	for (size_t i = 0; i < size; i++) {
		cout << v.get(i) << endl;
	}
}
int main() {
	IntVector v{};
	IntVector v2{};
	v = v2;
	return 0;
}
