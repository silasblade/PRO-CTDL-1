#pragma once
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<windows.h>
#include<string>
#include<math.h>
#include<iomanip>
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

void listUser() 
{
	system("cls");
	string user[100];
    string pin[100];
    int i=0;
    ifstream is("TheTu.txt");
	getline(is, user[0]);
	getline(is, pin[0]);
	i++;
    while(!pin[i-1].empty())
    {
        getline(is, user[i]);
        getline(is, pin[i]);
        i++;
    }
    is.close();
	cout << "\t\t\t\t**** Thong tin cac nguoi dung ****" << endl;
	cout << endl;

	for(int k=1; k<i; k++)
	{
		cout << "\t\t\t\tUser " << k << "  :" << user[k-1] << endl;
		cout << "\t\t\t\tPIN     :" << pin[k-1] << endl;
		cout << endl;
	}

	cout << "\t\t\t\tNhan phim bat ky de quay lai menu." << endl;
	cout << "\t\t\t\t";
	system("pause");
	adminMenu();

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
	system("cls");
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
			adminLogin();
	}
}

void adminLogin() 
{
	system("cls");
	string user[100];
    string pin[100];
    int i=0;
    ifstream is("Admin.txt");
	getline(is, user[0]);
	getline(is, pin[0]);
	i++;

    while(!pin[i-1].empty())
    {
        getline(is, user[i]);
        getline(is, pin[i]);
        i++;
    }
    is.close();

	system("cls");
    string id, password;
	cout << "\t\t\t\t**************************************************\n";
	cout << "\t\t\t\t*\t\t  DANG NHAP ADMIN\t\t *\n";
	cout << "\t\t\t\t**************************************************\n";
	cout << "\n\t\t\t\tUser: "; cin >> id;
	cout << "\n\t\t\t\tPassword: ";
	
    Pass(password);

    for(int j=0; j<i; j++)
    {
       if(id==user[j] && password==pin[j]) adminMenu();
    }

	cout << endl;
	cout << "\t\t\t\tNhap sai mat khau hoac tai khoan, vui long nhap lai." << endl;
	cout << "\t\t\t\t";
	system("pause");
	adminLogin();
	
	
}
