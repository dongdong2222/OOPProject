#pragma once
#include <cstring>
#include <iostream>
using namespace std;


class Employee
{
private:
	char name[30];
public:
	Employee(const char* name)
	{
		strcpy_s(this->name, 30, name);
	}
	void ShowYourName() const
	{
		cout << "name : " << name << endl;
	}
};
class PermanentWorker :public Employee //정규직
{
private:
	char name[30];
	int salary; //매달 지급해야하는 급여
public:
	PermanentWorker(const char* name, int money) :Employee(name),salary(money)
	{
	}
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay) : Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay() const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "sarary: " << GetPay() << endl;
	}
};

class SalesWorker :public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSaleResult(int value)
	{
		salesResult += value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary : " << GetPay() << endl;
	}
};
class EmployeeHandler
{
private:
	Employee* emList[50];
	int emNum;
public:
	EmployeeHandler() :emNum(0)
	{ }

	void AddEmployee(Employee* emp)
	{
		emList[emNum++] = emp;
	}

	void ShowAllSalaryInfo() const
	{
		for (int i = 0; i < emNum; i++)
		{
			//emList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const
	{
		int sum = 0;
		for (int i = 0; i < emNum; i++)
		{
			//sum += emList[i]->GetPay();
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
