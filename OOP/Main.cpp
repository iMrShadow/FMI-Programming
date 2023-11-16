#include <iostream>
#include <fstream>
#include <string>
#include "Database.cpp"
using namespace std;

int main() {
	string s;
	bool login = false;
	ifstream fin("database.db", ios::binary);
	try {
		if (!fin) throw std::runtime_error("Invalid file");
		DataBase database(fin, "database.db");
		while (!login) {
			cout << "Please enter username and password: " << endl;
			string name, password;
			cin >> name >> password;
			if (database.isValidLogIn(fin, "database.db")) { //check if login is correct
				login = true;
			}

		}

		while (s != "Exit") {
			//INSERT COMMANDS HERE
		}
	}
	catch (std::exception e) {
		cout << e.what << endl;
	}
	return 0;
}
