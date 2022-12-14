#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<conio.h>
#include"User.h"

using namespace std;


void adminMenu();
void userMenu();
void adminLogin();
void Pass(string &password){
	string P;
	char p;
	cout << "\n\t\t\t\tPassword: ";
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

string createId() {
	static const char alphanum[] = "0123456789";
	string id = "10000";
	string n;
	cout << "Tao id moi(9 So) : "; cin >> n;
	if (n.length() < 9 || n.length()>9) {
		cout << "\nId khong hop le. Moi tao lai.";
		Sleep(2*1000);
		system("CLS");
		createId();
	}
	id += n;
	string User;
	string list[100];
	int i = 0;
	ifstream listFile("TheTu.txt");
	while (getline(listFile, User)) {
		string getIdFile = User.substr(0, 14);
		list[i] = getIdFile;
		i++;
	}
	listFile.close();
	for (int j = 0;j < i+1;j++) {
		if (id == list[j]) {
			cout << "\nId da ton tai. Nhap Id Khac";
			Sleep(2 * 1000);
			system("CLS");
			createId();
		}
	}

	return id;
}
//Permisson

void listUser() {
	string user;
	int i = 0;
	ifstream listFile("TheTu.txt");
	while (getline(listFile, user)) {
		i++;
		cout << "User "<< i << " : " << user << "\n";
	}
	listFile.close();
	int thoat;
	cout << "Quay lai Menu(nhan phim 0 de quay lai) : ";cin >> thoat;
	if (thoat == 0) {
		system("CLS");
		adminMenu();
	}
}

void addNewUser() {
	string id = createId();
	string pin = "123456";
	string log = "0";
	string userFile = id + ".txt";
	ofstream NewUser(userFile);
	ofstream TheTu("TheTu.txt", ios_base::app);
	NewUser << id <<endl<< pin <<endl <<log;
	TheTu << id << " " << pin << endl;
	NewUser.close();
	TheTu.close();
	cout << "Tao thanh cong\n";
}

void deleteUser() {
	string id, user, getIdFile;
	cout << "Quay lai Menu(nhan phim 0 de quay lai)\n";
	cout << "Nhap id can xoa: ";cin >> id;
	if (id.compare("0") == 0) {
		system("CLS");
		adminMenu();
	}
	else {
		ifstream listFile("TheTu.txt");
		ofstream User("NewTheTu.txt", ios_base::app);
		while (getline(listFile, user)) {
			getIdFile = user.substr(0, 14);
			if (getIdFile == id) {
				user = "";
				User << user;
			}
			else {
				User << user << endl;
			}
		}
		User.close();
		listFile.close();
		remove("TheTu.txt");
		rename("NewTheTu.txt", "TheTu.txt");

		id += ".txt";
		char fileName[20];
		strcpy_s(fileName, id.c_str());
		if (remove(fileName) != 0)
			cout << ("Loi xoa file!\nId ban can xoa khong ton tai");
		else
			cout << ("Xoa thanh cong");
	}
}

void adminMenu() {
	cout << "\t\t\t\t**************************Menu*************************\n";
	cout << "\t \t \t\t\t\t1. Xem danh sach tai khoan.\n";
	cout << "\t \t \t\t\t\t2. Them tai khoan.\n";
	cout << "\t \t \t\t\t\t3. Xoa tai khoan.\n";
	cout << "\t \t \t\t\t\t4. Mo khoa tai khoan.\n";
	cout << "\t \t \t\t\t\t5. Thoat.\n";
	cout << "\t\t\t\t*******************************************************\n";
	cout << "\t \t\t\t\t\t Enter your choice: ";
	int n;
	cin >> n;
	const int delay = 1000000*2;
	system("CLS");
	switch(n){
		case 1:
			listUser();
			system("CLS");
			adminMenu();
		case 2:
			addNewUser();
			cout << "\nDoi trong giay lat";
			Sleep(2*1000);
			system("CLS");
			adminMenu();
		case 3:
			deleteUser();
			cout << "\nDoi trong giay lat";
			Sleep(2 * 1000);
			system("CLS");
			adminMenu();
		case 5:
			cout << "Doi trong giay lat";
			Sleep(2 * 1000);
			system("CLS");
			adminLogin();
	}
}

void adminLogin() 
{
	string user[100];
    string pin[100];
    int i=0;
    ifstream is("Admin.txt");
    while(!is.eof())
    {
        getline(is, user[i]);
        getline(is, pin[i]);
        i++;
    }
    is.close();

    bool right;
    do
    {
    string id, password;
    right=false;
	cout << "\t\t\t\t**************************************************\n";
	cout << "\t\t\t\t*\t\t  DANG NHAP ADMIN\t\t *\n";
	cout << "\t\t\t\t**************************************************\n";
	cout << "\n\t\t\t\tUser: ";cin >> id;
    Pass(password);
    for(int j=0; j<=i; j++)
    {
       if(id==user[i] && password==pin[i]) right==true;   
    }
    }
    while(right==false);
    adminMenu();
};
