#include <iostream>
#include <vector>
#include "Restaurant.hpp"

using std::string;
using std::vector;

class Client {
	string email;
	string phone;
	vector<Restaurant*> subsriptions;

public:
	void subscribe(Restaurant&);
	void notify() const;
	void unsubscribe(Restaurant&);
};
