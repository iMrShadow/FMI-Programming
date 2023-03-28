#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>


struct Record {
	int day, month, year;
	double temp;
};

std::istream& operator>>(std::istream& is, Record& r) {
	is >> r.day;
	is.ignore(1, '/');
	is >> r.month;
	is.ignore(1, '/');
	is >> r.year;
	is.ignore(1, ',');
	is >> r.temp;
	is.ignore(INT_MAX, '\n');
	return is;
}

std::ostream& operator<<(std::ostream& os, Record& r) {
	std::cout << r.day << '/' << r.month << '/' << r.year << ',' << r.temp;
	return os;
}
struct YearlyStats {
	int year;
	double sum;
	size_t count;
	Record min;
	Record max;

	YearlyStats(int year) {
		this->count = 0;
		min.temp = INT_MAX;
		max.temp = INT_MIN;
		this->year = year;
		this->sum = 0;
	}
	void yearStats() {
		double avg = 0;
		bool found = false;

		std::ifstream fin("temperature.csv");
		if (!fin) {
			std::cerr << "NO FILE YOU DONKEY!" << std::endl;
		}
		fin.ignore(INT_MAX, '\n');

		Record r;
		while (fin >> r) {
			if (r.year == year) {
				found = true;
			}
			if (found) {
				if (r.year != year) {
					break;
				}
				if (min.temp >= r.temp) {
					this->min = r;
				}
				if (max.temp <= r.temp) {
					this->max = r;
				}
				this->sum += r.temp;
				this->count++;
			}
		}
		std::cout << std::setprecision(3)<< year << ' ' << count << ' ' << (double)sum / count << ' ' << min.temp << ' ' << max.temp << ' ' << std::endl;
	}
};


int main() {
	//ignore first header line
	//fin.ignore(INT_MAX, '\n');

	for (size_t i = 1981; i < 1990; i++) {
		YearlyStats s(i);
		s.yearStats(); 
	}
	
	return 0;
}