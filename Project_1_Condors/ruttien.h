
#pragma once
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <vector>
#include "Permisson.h"
#include <cstdlib>
#include <ctime> 
#include <vector>
#include <sstream>

#include "userreal.h"

using namespace std;

void giaoDienMenu();

void lsgd(string idgd, float sotien, string phuongthuc, string ten, string donvi)
{
    time_t now = time(0);
    char* dt = ctime(&now);
    int i=1;

    string file="LichSu";
    file=file+idgd;
    
    ofstream os("ID_User/" + file + ".txt", ios::app);
    {
        os << dt;
        os << idgd << endl;
        os << ten << endl;
        if(phuongthuc=="Rut tien" || phuongthuc=="Chuyen tien")
        os << "-" << sotien << " " << donvi << endl;
        os << "<" << phuongthuc << ">" << endl;
        os << "\n";
    }
    os.close();
}

void ruttien()
{
    cout << fixed << setprecision(0);
    system("cls");

    //Nhap file lay cac thong tin nguoi dung de xuat so du hien tai
    string file="ID_User/";
    string x[5];
    ifstream is(file+currentuser+".txt");
    for(int i=1; i<=5; i++)
    {
        getline(is, x[i]);
    }
    is.close();
    stringstream cre;
    cre << x[3];
    float credit;
    cre >> credit;
    cout << "\t\t\t\tSo du tai khoan cua ban la: " << x[3] << " " << x[4] << endl;

    //Dieu kien rut tien
    if(credit < 50000 && x[4]=="VND")
    {
    cout << "\t\t\t\tTai khoan cua ban khong du de rut" << endl;
    cout << "\t\t\t\tNhan phim bat ky de tro lai menu" << endl;
    system("pause");
    giaoDienMenu();
    }

    if(credit < 2.1 && x[4]=="USD")
    {
    cout << "\t\t\t\tTai khoan cua ban khong du de rut" << endl;
    cout << "\t\t\t\tNhan phim bat ky de tro lai menu" << endl;
    system("pause");
    giaoDienMenu();
    }

    //Thuc hien rut tien
    cout << "\t\t\t\tNhap so tien muon rut: ";
    float rut=0;
    cin >> rut;
    long tienle=rut;
    if(tienle % 50000 !=0 || rut <50000)
    {
        cout << "\t\t\t\tSo tien ban nhap khong hop le. Vui long nhan Enter roi tien hanh nhap lai." << endl;
        system("pause");
        ruttien();
    }
    cout << "\t\t\t\tBan da rut " << rut << " " << x[4] << " khoi tai khoan." << endl;
    float conlai;
    conlai=credit - rut;
    stringstream con;
    con << conlai;
    lsgd(currentuser, rut, "Rut tien", x[2], x[4]);
    con >> x[3];
    cout << "\t\t\t\tSo tien con lai trong tai khoan la: " << x[3] <<  " " << x[4] << endl;

    //Cap nhat lai thong tin
    ofstream os("ID_User/" + currentuser+".txt");
    for(int i=1; i<=5; i++)
    {
        os << x[i] << endl;
    }
    os.close();

    

    cout <<"\t\t\t\tChon chuc nang:" << endl;
    cout <<"\t\t\t\t1. De rut tien lan nua" << endl;
    cout <<"\t\t\t\t2. De tro lai menu" << endl;
    cout <<"\t\t\t\tChon: ";
    int choose;
    cin >> choose;
    if(choose==1) ruttien();
    if(choose==2) giaoDienMenu();
}

#include "userreal.h"

