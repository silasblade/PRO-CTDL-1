#pragma once
#include "lib.h"
#include "Admin.h"

using namespace std;

void adminMenu();

void moKhoaTaiKhoan()
{
    system("cls");
    cout << "\t\t\t\t**** Mo khoa tai khoan ****" << endl;
    cout << endl;
    cout << "\t\t\t\tNhap ID tai khoan muon mo khoa: ";
    string id;
    cin >> id;

    
    string user[100];
    string pin[100];
    int m=0;
    ifstream is1("TheTu.txt");
	getline(is1, user[0]);
	getline(is1, pin[0]);
	m++;
    while(!pin[m-1].empty())
    {
        getline(is1, user[m]);
        getline(is1, pin[m]);
        m++;
    }
    is1.close();

    int checkdel=0;
	int numdel;
	for(int k=0; k<m-1; k++)
	{
		if(id==user[k]) {checkdel++; numdel=k;}
	}

    if(checkdel==0)
	{
		cout << "\t\t\t\tID khong ton tai." << endl;
		cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
        cout << "\t\t\t\t";
		system("pause");
		moKhoaTaiKhoan();
	}

    

    string tt[10];
    int khoa;
    ifstream is("ID_User/" + id + ".txt");
    int i=0;
    getline(is, tt[i]); i++;
    getline(is, tt[i]); i++;
    getline(is, tt[i]); i++;
    getline(is, tt[i]); i++;
    is >> khoa;
    is.close();

    khoa=0;
    
    i=0;
    ofstream os("ID_User/" + id + ".txt");
    os << tt[i] << endl; i++;
    os << tt[i] << endl; i++;
    os << tt[i] << endl; i++;
    os << tt[i] << endl; i++;
    os << khoa << endl;

    cout << endl;
    cout << "\t\t\t\tTai khoan nay da duoc mo khoa!!!" << endl;
	cout << "\t\t\t\tNhan phim bat ky de tro lai menu." << endl;
	cout << "\t\t\t\t";
	system("pause");
    adminMenu();

}