#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class PermanentWorker
{
private:
	char name[30];
	int salary; //매달 지급해야하는 급여
public:
	PermanentWorker(const char* name, int money) :salary(money)
	{
		strcpy_s(this->name, 30, name);
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		cout << "name: " << name << endl;
		cout << "salary: " << salary << endl;
	}
};

class EmployeeHandler
{
private:
	PermanentWorker* emList[50];
	int emNum;
public:
	EmployeeHandler() :emNum(0)
	{ }

	void AddEmployee(PermanentWorker* emp)
	{
		emList[emNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < emNum; i++)
		{
			emList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < emNum; i++)
		{
			sum += emList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < emNum; i++) {
			delete emList[i];
		}
	}
};

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

};

class Derived : protected Base
{

};
