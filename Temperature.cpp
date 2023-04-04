#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

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
		std::cout << std::setprecision(3) << year << ' ' << count << ' ' << (double)sum / count << ' ' << min.temp << ' ' << max.temp << ' ' << std::endl;
	}
};


struct StudentRecord {
	char studentID[10];
	char courseID[6];
	int note;

	StudentRecord() : studentID("\0"), courseID("\0"), note(0) {}
	StudentRecord(const char studentID[10], const char courseID[6], const int note) : note(note) {
		for (size_t i = 0; i < 10; i++) {
			this->studentID[i] = studentID[i];
		}
		for (size_t i = 0; i < 6; i++) {
			this->courseID[i] = courseID[i];
		}
	}

	std::vector<int> getStudentNotes(const char* studentID) {
		std::ifstream f("student_records.data", std::ios::in || std::ios::binary);
		if (!f) {
			std::cerr << "NO FILE YOU DONNO!" << std::endl;
		}
		StudentRecord r;
		std::vector<int> vec;
		while (f.read((char*)&r, sizeof(r))) {
			if (strncmp(r.studentID, studentID, 10) == 0) {
				vec.push_back(r.note);
			}
		}
		return vec;
	}
	std::vector<int> getCourseNotes(const char* courseID) {
		std::ifstream f("student_records.data", std::ios::in || std::ios::binary);
		if (!f) {
			std::cerr << "NO FILE YOU DONNO!" << std::endl;
		}
		StudentRecord r;
		std::vector<int> vec;
		while (f.read((char*)&r, sizeof(r))) {
			if (strncmp(r.courseID, courseID, 6) == 0) {
				vec.push_back(r.note);
			}
		}
		return vec;
	} 
//	AOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO THEEEEEEEEEEEEE OOOOOOOOOOOONE THE OOOOOOOOOONLYYY THEEEEE UNDDDDDEEEEEEEEEEERRRRRRRTAAAAAAKEEEEEEEEEEEEEEEEEEEEEERRRRRRRRRRRR
	double getStudentAverage(const char* studentID) {
		double sum = 0;
		std::vector<int> v = getStudentNotes(studentID);
		for (size_t i = 0; i < v.size(); i++) {
			sum += v.at(i);
		}
		return sum / v.size();
	}
	double getCourseAverage(const char* courseID) {
		double sum = 0;
		std::vector<int> v = getCourseNotes(courseID);
		for (size_t i = 0; i < v.size(); i++) {
			sum += v.at(i);
		}
		return sum / v.size();
	}
};

int main() {
	//ignore first header line
	//fin.ignore(INT_MAX, '\n');

	/*for (size_t i = 1981; i < 1990; i++) {
		YearlyStats s(i);
		s.yearStats();
	}*/
	StudentRecord r;
	std::vector<int> vec = r.getStudentNotes("Calculus");
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec.at(i);
	}
	return 0;
}