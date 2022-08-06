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
		cout << "계좌ID : " << id << endl;

		cout << "이 름 : " << name << endl;

		cout << "잔 액 : " << balance << endl;

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
		std::cout << "1. 계좌 개설" << std::endl;
		std::cout << "2. 입 금" << std::endl;
		std::cout << "3. 출 금" << std::endl;
		std::cout << "4. 전체 계좌 출력 " << std::endl;
		std::cout << "5. 종 료" << std::endl;
		std::cout << "선택 : ";
		std::cin >> select;

		return select;
	}

	void MakeAccount() {

		int id;
		char name[20];
		int balance;
		std::cout << "계좌 ID : ";
		std::cin >> id;
		std::cout << "입금자명 : ";
		std::cin >> name;
		std::cout << "입금액 : ";
		std::cin >> balance;

		AccList[accCount++] = new Account(id, name, balance);
	}
	void Deposit() {
		int id, amount;
		std::cout << "[입   금]" << endl << "입금자 ID : ";
		cin >> id;
		cout << "입금액 : ";
		std::cin >> amount;

		AccList[GetIndex(id)]->Deposit(amount);
	}

	void Withdraw() {
		int id, amount;
		std::cout << "[출   금]" << endl << "출금자 ID : ";
		cin >> id;
		cout << "출금액 : ";
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



