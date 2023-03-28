#include <iostream>
#include <stdexcept>
#include <cassert>
#include <string>
#include "Vector.hpp"

void print(std::string s){
	for (size_t i = 0;  i < s.size();  i++) { //she me ubiete za size
		std::cout << s[i];
	}
	std::cout<<std::endl;
}

bool checkBalance(std::string s) {
	int mask[6]={};
	std::string copy;
	size_t size = s.size();
	int newsize = 0;
	for (size_t i = 0; i < size; i++) {
		if (s[i] == '(' || s[i] == '{' || s[i] == '[' || s[i] == ']' || s[i] == '}' || s[i] == ')') {
			copy+=s[i];
			newsize++;
		}
	}
	
	if (copy.size() % 2 != 0) {
		return false;
	}
	print(copy);
	char currC = ' ';
	size_t ind = 0;
	for (size_t i = 0; i < newsize; i++) {
		print(copy);
		switch (copy[i]) {
		case '(': currC = copy[i]; ind = i; break;
		case '{': currC = copy[i]; ind = i; break;
		case '[': currC = copy[i]; ind = i; break;
		case ')': if (currC != '(') return false; else copy[i] = '#'; copy[ind] = '#'; i = 0; break;
		case '}': if (currC != '{') return false; else copy[i] = '#'; copy[ind] = '#'; i = 0; break;
		case ']': if (currC != '[') return false; else copy[i] = '#'; copy[ind] = '#'; i = 0; break;
		}
		std::cout << currC;

	}
	
	for (size_t i = 0; i < size; i++) {
		if (copy[i] != '#') {
			return false;
		}
	}

	return true;
}



//std::string s;
//IntVector vec;
//int a = 5;
////vec.append();
//vec.append(1);
//vec.append(1);
//vec.append(1);
//vec.insert(2, 3);
////vec.remove(2);
//vec.print(vec);
//std::cout << vec.find(3);


