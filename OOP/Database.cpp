#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
	int str_size;
	string name;
	string password;
	string role;

public:
	User() : name(""), password(""), role("") {}
	User(string name, string password, string role) : name(name), password(password), role(role) {}

	friend bool isValidUser() { //Checks for whitespaces
		if (name.contains(" ")) {
			cout << "Name is not valid!" << endl;
			return false;
		}
		if (password.contains(" ")) {
			cout << "Password is not valid!" << endl;
			return false;
		}
		return true;
	}
	bool checkIsAdmin() {
		if (role == "Admin"||role=="Administrator") {
			return true;
		}
		return false;
	}
};

class Product {
	string barcode;
	string type;
	double price;
	int quantity;

public:
	Product() : barcode(), type(), price(0), quantity(0) {}
	Product(string barcode, string type, double price, int quantity) : barcode(barcode), type(type), price(price), quantity(quantity) {}

};

class DataBase {
	User user;
	Product product;
	size_t user_count;
	size_t product_count;
	bool logged_in;

public:
	DataBase() {
		user_count = 0;
		product_count = 0;
		logged_in = false;
		
	}
	DataBase(istream& is, string fileName) {
		string user_size, product_size;
		is >> user_size >> product_size;
		logged_in = false;
	}

	bool checkLength(string s) { //check if the string is above 50 characters
		if (s.length() > 50) {
			return false;
		}
		return true;
	}
	 
	bool isValidLogIn(istream& is, string username, string password) { //there is a user
	   is.ignore(100,'\n'); //ignoring the first line, because the usercount and productcount are supposed to be written there
	  // is it possible to "skip" in binary files?
	   int i = 0; //counter for total amount of users checked
	   User user;
	   while (i<user_count) {
	   	is.ignore();
	   	if (i == user_count) {
	   		throw std::exception("There is no such username!");
	   	}
	   	string usernamec, passwordc;
	   	is >> usernamec >> passwordc;
	   	if (usernamec == username) {
			if (passwordc == password) {
				cout << "You are logged in!" << endl;
				logged_in = true;
				return true;
			}
			else {
				throw std::exception("Wrong password!");
			}
	   	}
	   	i++;
	   }
	}
	void addUser(User loggedIn, User toBeAdded) {
		if (loggedIn.checkIsAdmin()) {
			cout << "You are not permitted to add Users" << endl;
		}
		//
	}
	void addProduct(Product toBeAdded) {
		//add product
	}
	void changeProductQuantity(Product prod) {

	}
	void changeProductPrice(User loggedIn,Product prod) {
		if (loggedIn.checkIsAdmin()) {
			cout << "You are not permitted to add Users" << endl;
		}
	}
	bool productExists(Product prod) {
		//check if product exists
	}
	void removeProduct(User loggedIn, Product toBeAdded) {
		if (loggedIn.checkIsAdmin()) {
			cout << "You are not permitted to add Users" << endl;
		}
	}
};
