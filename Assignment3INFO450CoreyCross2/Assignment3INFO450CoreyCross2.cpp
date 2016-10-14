// Assignment3INFO450CoreyCross2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Account
{
public:
	Account();
	Account(double balance);
	void Add(double money);
	void Withdraw(double money);
	double GetBalance();

private:
	double balance;
};

void deposit(double, string);
void withdraw(double, string);
void transfer(double, string);
void printBalances();


int main()
{
	string accountChoice;
	int selection;
	double transaction = 0;



	do
	{
		cout << "Please make a selection:" << endl;
		cout << "1.) Deposit" << endl;
		cout << "2.) Withdraw" << endl;
		cout << "3.) Transfer" << endl;
		cout << "4.) Print balances" << endl;
		cout << "5.) Quit" << endl;
		cin >> selection;

		if (selection == 1)
		{
			cout << endl << "Please select the account you would like to perform operations on(S or C):" << endl;
			cin >> accountChoice;
			cout << endl << "Please enter the amount to be deposited:" << endl;
			cin >> transaction;
			cout << endl;

			deposit(transaction, accountChoice);
		}
		else if (selection == 2)
		{
			cout << endl << "Please select the account you would like to perform operations on(S or C):" << endl;
			cin >> accountChoice;
			cout << endl << "Please enter the amount to be withdrawn:" << endl;
			cin >> transaction;
			cout << endl;

			withdraw(transaction, accountChoice);
		}
		else if (selection == 3)
		{
			cout << endl << "Please select the account you would like to perform operations on(S or C):" << endl;
			cin >> accountChoice;
			cout << endl << "Please enter the amount to be transferred:" << endl;
			cin >> transaction;
			cout << endl;

			transfer(transaction, accountChoice);
		}
		else if (selection == 4)
			printBalances();
		else
			cout << "Closing program -- Thank you for using the ATM teller!" << endl;
	} while (selection != 5);


	return 0;
}

void deposit(double amount, string account)
{
	Account savings, checking;

	if (account == "S" || account == "s")
		savings.Add(amount);
	else
		checking.Add(amount);
}

void withdraw(double amount, string account)
{
	Account savings, checking;

	if (account == "S" || account == "s")
		savings.Withdraw(amount);
	else
		checking.Withdraw(amount);
}

void transfer(double amount, string account)
{
	Account savings, checking;

	if (account == "S" || account == "s")
	{
		savings.Withdraw(amount);
		checking.Add(amount);
	}
	else
	{
		checking.Withdraw(amount);
		savings.Add(amount);
	}
}

void printBalances()
{
	Account savings, checking;

	cout << "The current balance in savings is: " << savings.GetBalance() << endl;
	cout << "The current balance in checking is: " << checking.GetBalance() << endl << endl;
}

//  Penalty Fee Constant
const double PENALTY_FEE = 5.00;

Account::Account()
{
	balance = 0.00;
}

Account::Account(double money)
{
	balance = money;
}

void Account::Add(double money)
{
	balance += money;
}

void Account::Withdraw(double money)
{
	if (money > balance)
		balance += PENALTY_FEE;
	else
		balance -= money;
}

double Account::GetBalance()
{
	return balance;
}

