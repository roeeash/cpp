#ifndef USER_H
#define USER_H

class User {
private:
	int balance;

public:
	User() {
		this->balance = 0;
	}
	User(int balance) {
		this->balance = balance;
	}
	//getter
	int getBalance() {
		return this->balance;
	}
	//setter
	void setBalance(int balance) {
		this->balance = balance;
	}
};
#endif