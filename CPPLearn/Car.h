#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class Car
{
private:
	int gasolineGauge;
public:
	Car() :gasolineGauge(0)
	{

	}
	int GetGasGauge() const
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car

{
private:
	int electricGauge;
public:
	HybridCar() :Car(), electricGauge(0)
	{

	}
	int GetElecGauge() {
		return electricGauge;
	}

};

class SoBase {
private:
	int baseNum;
public:
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;

	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:

	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() :" << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() :" << derivNum << endl;
	}
};
class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* name, int age) : age(age)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
	}
	~MyFriendInfo()
	{
		delete[]name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
public:
	MyFriendDetailInfo(const char* name, int age, const char* addr) :MyFriendInfo(name, age)
	{
		int len = strlen(addr) + 1;
		this->addr = new char[len];
		strcpy_s(this->addr, len, addr);

	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
	}
};

