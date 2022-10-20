#pragma once
#include"lib.h"
#include"lock.h"

using namespace std;

void moKhoaTaiKhoan();
void adminMenu();
void adminLogin();
void Pass(string &password){
	int ch;
	int i=0;
    ch=getch();
    while(ch!=13)
    {
        password.push_back(ch);
        if(ch==8 && i>0)
        {
		i--;
        cin.clear();
        cout << '\b';
        cout << " ";
        cout << '\b';
        }

		else if(ch==8 && i==0)
		{
			cin.clear();
		}

        else
		{
		i++;
        cout << "*";
		}
        ch=getch();
		
    }
}



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

void listdel() 
{
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
	cout << "\t\t\t\tDanh sach nguoi dung: " << endl;
	cout << endl;

	for(int k=1; k<i; k++)
	{
		cout << "\t\t\t\tUser " << k << "  :" << user[k-1] << endl;
		cout << "\t\t\t\tPIN     :" << pin[k-1] << endl;
		cout << endl;
	}
}

void addNewUser() {
	system("cls");

    string u[100];
    string p[100];
    int i=0;
    ifstream is("TheTu.txt");
	getline(is, u[0]);
	getline(is, p[0]);
	i++;
	while(!p[i-1].empty())
    {
        getline(is, u[i]);
        getline(is, p[i]);
        i++;
    }
    is.close();


	cout << "\t\t\t\t**** Them nguoi dung moi ****" << endl;
	string id;
	cout << "\t\t\t\tTao ID (14 chu so): ";
	cin >> id;
    
    for(int k=0; k<i-1; k++)
	{
		if(id==u[k])
		{
			cout << "\t\t\t\tID da ton tai, vui long nhap lai. Nhan Enter de tiep tuc." << endl;
			system("pause");
			addNewUser();
		}
	}

	string pin;
	pin="123456";
	cout << "\t\t\t\tNhap ten nguoi dung: ";
	string ten;
	cin.ignore();
	getline(cin, ten);
	cout << "\t\t\t\tNhap so tien duoc nap vao ban dau (>=50000 VND): ";
	string tien;
	cin >> tien;
	string donvi = "VND";
	int solannhapsai = 0;

    ofstream TheTu("TheTu.txt", ios_base::app);
	TheTu << id << endl;
	TheTu << pin << endl;
    TheTu.close();

	ofstream NewUser("ID_User/" + id + ".txt");
	NewUser << id << endl;
	NewUser << ten << endl;
	NewUser << tien << endl;
	NewUser << donvi << endl;
	NewUser << solannhapsai << endl;
    NewUser.close();

	cout << "\t\t\t\tNguoi dung duoc tao thanh cong\n";
	cout << "\t\t\t\tNhan phim bat ky de tro lai menu." << endl;
	system("pause");
    adminMenu();
}

void deleteUser() {
	listdel();

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


    int checkdel=0;
	int numdel;
	string id;
	cout << "\t\t\t\tNhap id can xoa: "; cin >> id;
	for(int k=0; k<i-1; k++)
	{
		if(id==user[k]) {checkdel++; numdel=k;}
	}

    if(checkdel==0)
	{
		cout << "\t\t\t\tID ban nhap khong dung." << endl;
		cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
		system("pause");
		deleteUser();
	}
    
	string addres="ID_User/";
	addres=addres+id+".txt";
	string lichsu="ID_User/LichSu";
	lichsu=lichsu+id+".txt";
	const char *c = addres.c_str();
	const char *d = lichsu.c_str();
	remove(c);
    remove(d);
	
	ofstream updatett("TheTu.txt");
	for(int j=0; j < numdel; j++)
    {
		updatett << user[j] << endl;
		updatett << pin[j] << endl;
	}

	for(int n=numdel+1; n < i-1; n++)
    {
		updatett << user[n] << endl;
		updatett << pin[n] << endl;
	}
	updatett.close();

	cout << "\t\t\t\tBan da xoa thanh cong nguoi dung." << endl;
	cout << "\t\t\t\tChon chuc nang tiep theo: " << endl;
	cout << "\t\t\t\t1. Xoa nguoi dung tiep theo. " << endl;
	cout << "\t\t\t\t2. Quay lai menu. " << endl;
	cout << "\t\t\t\tChon:  " << endl;
	int a;
	cin >> a;
	if(a==1) deleteUser();
	if(a==2) adminMenu();
}

void adminMenu() {
	system("cls");
	cout << "\t\t\t\t************************* Menu ************************\n";
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
		case 2:
			addNewUser();
		case 3:
			deleteUser();
		case 4:
		    moKhoaTaiKhoan();
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
