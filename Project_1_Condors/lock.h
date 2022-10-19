#pragma once
#include "lib.h"
#include "Admin.h"

using namespace std;

void adminMenu();

void moKhoaTaiKhoan()
{
    cout << "\t\t\t\t**** Mo khoa tai khoan ****" << endl;
    cout << endl;
    cout << "\t\t\t\tNhap ID tai khoan muon mo khoa: " << endl;
    string id;
    cin >> id;

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

    cout << "\t\t\t\tTai khoan nay da duoc mo khoa thanh cong!!!" << endl;
    cout << "\t\t\t\t________________________________" << endl;
    cout << "\t\t\t\tChon chuc nang tiep theo: " << endl;
    cout << "\t\t\t\t1. Mo khoa tai khoan tiep theo." << endl;
    cout << "\t\t\t\t2. Ve menu." << endl;
    cout << "\t\t\t\tNhap: ";
    int chon;
    cin >> chon;
    if(chon==1) moKhoaTaiKhoan();
    if(chon==2) adminMenu();

}