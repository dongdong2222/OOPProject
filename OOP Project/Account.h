#pragma once
#include <cstring>
#include <iostream>
using namespace std;

enum CASE { MAKE = 1, DEPOSIT, WITHDARW, INQUIRE, EXIT };

class Account
{
private:
	int id;
	char* name;
	int balance;
public:
	Account(int pid, const char* pname, int pbal) : id(pid), balance(pbal) {
		int len = strlen(pname) + 1;
		name = new char[len];
		strcpy_s(name, len, pname);

	}
	~Account() {
		delete[]name;
	}
	int GetId() const {
		return id;
	}
	int GetBalance() const {
		return balance;
	}
	void SetBalance(int money) {
		if (money < 0) {
			std::cout << "can't minus";
			return;
		}

		this->balance = money;
	}

	void Deposit(int money) {
		SetBalance(balance + money);
	}
	void Withdraw(int money) {
		SetBalance(balance - money);

	}

	void PrintInfo() {
		cout << "����ID : " << id << endl;

		cout << "�� �� : " << name << endl;

		cout << "�� �� : " << balance << endl;

		cout << endl;
	}

};

class AccountManager {
private:
	Account* AccList[20];
	int accCount;
public:
	AccountManager() {
		accCount = 0;
	}
	~AccountManager()
	{
		for (int i = 0; i < accCount; i++) {
			delete AccList[i];
		}
	}
	bool SelectMenu()
	{
		bool exit = true;
		int select = PrintMenu();
		switch (select) {
		case 1:
			MakeAccount();
			break;

		case 2:
			Deposit();
			break;

		case 3:
			Withdraw();
			break;

		case 4:
			PrintAll();
			break;

		case 5:

			return exit = false;

			break;

		default:

			std::cout << "select right Menu!";

			break;

		}
		return exit;
	}
	void PrintAll() {
		for (int i = 0; i < accCount; i++) {
			AccList[i]->PrintInfo();
		}
	}


	int PrintMenu() {
		int select;
		std::cout << "----Menu----" << std::endl;
		std::cout << "1. ���� ����" << std::endl;
		std::cout << "2. �� ��" << std::endl;
		std::cout << "3. �� ��" << std::endl;
		std::cout << "4. ��ü ���� ��� " << std::endl;
		std::cout << "5. �� ��" << std::endl;
		std::cout << "���� : ";
		std::cin >> select;

		return select;
	}

	void MakeAccount() {

		int id;
		char name[20];
		int balance;
		std::cout << "���� ID : ";
		std::cin >> id;
		std::cout << "�Ա��ڸ� : ";
		std::cin >> name;
		std::cout << "�Աݾ� : ";
		std::cin >> balance;

		AccList[accCount++] = new Account(id, name, balance);
	}
	void Deposit() {
		int id, amount;
		std::cout << "[��   ��]" << endl << "�Ա��� ID : ";
		cin >> id;
		cout << "�Աݾ� : ";
		std::cin >> amount;

		AccList[GetIndex(id)]->Deposit(amount);
	}

	void Withdraw() {
		int id, amount;
		std::cout << "[��   ��]" << endl << "����� ID : ";
		cin >> id;
		cout << "��ݾ� : ";
		std::cin >> amount;

		AccList[GetIndex(id)]->Withdraw(amount);
	}

	int GetIndex(int id) {
		for (int i = 0; i < accCount; i++) {
			if (AccList[i]->GetId() == id) {
				return i;
			}
		}
		return -1;
	}

};



