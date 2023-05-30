#include <iostream>
#include <vector>
#include "Dish.hpp"

using std::string;
using std::vector;

class Restaurant {
	string name;
	string address;
	string city;
	vector<Dish> menu;

	double avarageRating;
	unsigned numberOfRatings;
	vector<Client*> subscribers;

public:
	Restaurant(string brand, string loc, std::vector<Dish> menu);

	void rate(unsigned rating);
	void addSubs(Client*);
	void rmSubs(Client*);
	void addDish(const Dish&);
	void rmDish(const Dish&);
	vector<Dish> getDishes(string category);

};