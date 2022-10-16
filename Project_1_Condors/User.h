#pragma once
#include<iostream>
#include <string>
using namespace std;

class User{
private:
	string id, pin;
	const char* copyId = id.c_str();
	string checkLogin = "0";
public:
	void setId(string Id) {
		id = Id;
	}
	string getId() {
		return id;
	}
	void setPin(string Pin) {
		pin = Pin;
	}
	string getPin() {
		return pin;
	}

	int getCheckLogin() {
		ifstream user(copyId);
		user.ignore(256, '\n');
		user.ignore(256, '\n');
		getline(user, checkLogin);
		user.close();

		int CheckLogin = stoi(checkLogin);

		return CheckLogin;
	}
	void setCheckLogin(int a = 0) {
		checkLogin = a;
	}

};

