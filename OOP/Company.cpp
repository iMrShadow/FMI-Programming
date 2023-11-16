#include <iostream>
#include <vector>
#include "company.h"

using std::vector;

class Employee
{
private:
	int id;
public:
	virtual double salary() const = 0;
	Employee(const int id) : id(id) {}
	int getID() const {
		return id;
	}
};

class SalaryEmployee : public Employee
{
	double _salary;

public:
	double salary() {
		return _salary;
	}
	SalaryEmployee(const int id, const double salary) : Employee(id), _salary(salary) {}

};

class HourlyEmployee : public Employee
{
	double hourly_rate;
	int hours;
public:
	double salary() {
		return hourly_rate * hours;
	};
	HourlyEmployee(const int id, const int hours, const double hourly_rate) : Employee(id), hours(hours), hourly_rate(hourly_rate) {}
};

class CommissionEmployee : public Employee
{
	double baseSalary;
	bool premium;
	int numberOfSales;
public:
	double salary() {
		if (premium) {
			return baseSalary * 1.5 * numberOfSales;
		}
		else {
			return baseSalary * numberOfSales;
		}
	};
	CommissionEmployee(const int id, const double baseSalary, const bool premium, const int numberOfSales) : Employee(id), baseSalary(baseSalary), numberOfSales(numberOfSales), premium(premium) {}
};

class Company
{
	vector<Employee*> employees;
public:
	double calcSalaryExpenses() const
	{
		double salary = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			salary += employees[i]->salary();
		}
		return salary;
	}
	void addEmployee(Employee* e) {
		employees.push_back(e);
	}
};


//int main()
//{
//	Company com;
//
//	std::cout << com.calcSalaryExpenses() << std::endl;
//
//	return 0;
//}

