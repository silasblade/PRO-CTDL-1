#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include"User.h"

using namespace std;

void userLogin();

void Pin(string& password) {
	string P;
	char p;
	cout << "\n\t\t\t\tPin: ";
	p = _getch();
	while (p != 13)
	{
		if (p == 8)
		{
			P.resize(P.length() - 1);
			cout << P;
			password.resize(password.length() - 1);
		}
		else {
			cout << "*";
			password.push_back(p);
		}
		p = _getch();
	}
}

void userMenu() {
	cout << "\t\t\t\t**************************Menu*************************\n";
	cout << "\t \t \t\t\t\t1. Xem thong tin tai khoan.\n";
	cout << "\t \t \t\t\t\t2. Rut tien.\n";
	cout << "\t \t \t\t\t\t3. Chuyen tien.\n";
	cout << "\t \t \t\t\t\t4. Xem noi dung giao dich.\n";
	cout << "\t \t \t\t\t\t5. Doi ma Pin.\n";
	cout << "\t \t \t\t\t\t6. Thoat.\n";
	cout << "\t\t\t\t*******************************************************\n";
	cout << "\t \t\t\t\t\t Enter your choice: ";
	int n;
	cin >> n;
	switch (n) {
	case 6:
		system("CLS");
		cout << "Doi trong giay lat";
		Sleep(2 * 1000);
		system("CLS");
		userLogin();
	}
}

void userLogin() {
	string id, pin;
	User user;
	cout << "\t\t\t\t**************************************************\n";
	cout << "\t\t\t\t*\t\t  DANG NHAP USER\t\t *\n";
	cout << "\t\t\t\t**************************************************\n";
	cout << "\n\t\t\t\tID: ";cin >> id;
	Pin(pin);
	string fileid = id + ".txt";
	const char*  fileID = fileid.c_str();
	user.setId(id);
	user.setPin(pin);
	ifstream listFile(fileID);
	while (getline(listFile, id)) {
		if (id == user.getId()) {
			getline(listFile, pin);
			if (pin == user.getPin()) {
				system("CLS");
				userMenu();
				break;
			}
			else {
				system("CLS");
				userLogin();
			}
		}
	}
	listFile.close();
};