// ATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "User.h"

using namespace std;
/***
* @brief - void showMenu() - display menu to the user
**/
void showMenu() {
	cout << "************Menu************" << endl;
	cout << "Option 1: Check Balance" << endl;
	cout << "Option 2: Deposit" << endl;
	cout << "Option 3: Withdraw" << endl;
	cout << "Option 4: Transfer" << endl;
	cout << "Option 5: Exit" << endl;
	cout << "************************" << endl;

}
/**
* @brief - void transfer(User u1, User u2, int amount) - transfer amount
* from user u1 to user u2
***/
void transfer(User& u1, User& u2, int amount) {
	int u1Balance = u1.getBalance();
	if (u1Balance >= amount) {
		u1.setBalance(u1Balance - amount);
		u2.setBalance(u2.getBalance() + amount);
	
	}

}

/***
* @brief - int handleOption(int option, float balance) - handle user option
**/
int handleOption(int option, float balance) {
	switch (option) {
	case 1:
		cout << "Balance: " << balance << endl;
		return balance;
		break;
	case 2:
		float depositAmount;
		cout << "Enter amount to deposit:";
		cin >> depositAmount;
		balance += depositAmount;
		cout << "The current balance is :"<< balance<<endl;
		return balance;
	case 3:
		float withdrawAmount;
		cout << "Enter amount to withdraw:";
		cin >> withdrawAmount;
		if (withdrawAmount <= balance)
			balance -= withdrawAmount;
		else
			cout << "cannot withdraw more money than you own..." << endl;
		cout << "The current balance is :" << balance << endl;
		return balance;
	case 4:
		User u1 = User(1000);
		User u2 = User(1000);
		int transferAmount;
		cout << "Enter amount to transfer:";
		cin >> transferAmount;
		transfer(u1, u2, transferAmount);
		cout << "User 1 balance is: " << u1.getBalance() << endl;
		cout << "User 2 balance is: " << u2.getBalance() << endl;
	}
	return 0;

}


int main()
{
	int option = 0;
	float balance = 200.0;
	// main loop
	do {
		showMenu();
		cout << "Enter a value:";
		cin >> option;
		balance = handleOption(option, balance);
		system("pause>0");
		system("cls");
	}
	//option 5 to exit
	while (option != 5);
	
	return 0;
}
