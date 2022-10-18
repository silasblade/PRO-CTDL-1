
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

void lsgd(string idgd, float sotien, string phuongthuc, string ten, string donvi, string idnggd)
{
    time_t now = time(0);
    char* dt = ctime(&now);
    int i=1;

    string file="LichSu";
    file=file+idgd;
    
    ofstream os("ID_User/" + file + ".txt", ios::app);
    {
        os << dt;
        os << idnggd << endl;
        os << ten << endl;
        if(phuongthuc=="Rut tien" || phuongthuc=="Chuyen tien")
        os << "-" << sotien << " " << donvi << endl;
        if(phuongthuc=="Nhan tien")
        os << "+" << sotien << " " << donvi << endl;
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
    lsgd(currentuser, rut, "Rut tien", x[2], x[4], currentuser);
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

void chuyentien()
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
    cout << "\t\t\t\tTai khoan cua ban khong du de chuyen." << endl;
    cout << "\t\t\t\tNhan phim bat ky de tro lai menu." << endl;
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

    //Nhap ID nguoi can chuyen
    cout << "\t\t\t\tNhap ID nguoi ban muon chuyen tien: ";
    string tranuser;
    cin >> tranuser;

    //Kiem tra ton tai tai khoan
    ifstream is2;
    string addr="ID_User/";
    is2.open("ID_User/"+ tranuser +".txt");
    if(is2)
    {
        int trash=0;
    } 
    else
    {
    cout << "\t\t\t\tID khong ton tai." << endl;
    cout << "\t\t\t\tVui long nhap lai." << endl;
    system("pause");
    chuyentien();
    is2.close();
    }


    string y[5];
    for(int i=1; i<=5; i++)
    {
        getline(is2, y[i]);
    }
    is2.close();
    stringstream trancre;
    trancre << y[3];
    float nhantien;
    trancre >> nhantien;

    //Thuc hien rut tien
    cout << "\t\t\t\tNhap so tien muon chuyen: ";
    float chuyen=0;
    cin >> chuyen;
    long tienchuyen=chuyen;
    if(tienchuyen % 50000 !=0 || chuyen <50000)
    {
        cout << "\t\t\t\tSo tien ban nhap khong hop le. Vui long nhan Enter roi tien hanh nhap lai." << endl;
        system("pause");
        chuyentien();
    }

    cout << "\t\t\t\tBan da chuyen " << chuyen << " " << x[4] << " toi cho " << y[2] << endl;
    float conlai;
    conlai=credit - chuyen;
    float tiennhan;
    tiennhan=nhantien + chuyen;
    stringstream con;
    con << conlai;
    stringstream nhan;
    nhan << tiennhan;
    lsgd(currentuser, chuyen, "Chuyen tien", y[2], x[4], tranuser);
    lsgd(tranuser, chuyen, "Nhan tien", x[2], y[4], currentuser);

    con >> x[3];
    nhan >> y[3];
    cout << "\t\t\t\tSo tien con lai trong tai khoan la: " << x[3] <<  " " << x[4] << endl;

    //Cap nhat lai thong tin
    ofstream os("ID_User/"+ currentuser +".txt");
    for(int i=1; i<=5; i++)
    {
        os << x[i] << endl;
    }
    os.close();

    ofstream os2("ID_User/"+ tranuser +".txt");
    for(int i=1; i<=5; i++)
    {
        os2 << y[i] << endl;
    }
    os.close();

    

    cout <<"\t\t\t\tChon chuc nang:" << endl;
    cout <<"\t\t\t\t1. De chuyen tien lan nua" << endl;
    cout <<"\t\t\t\t2. De tro lai menu" << endl;
    cout <<"\t\t\t\tChon: ";
    int choose;
    cin >> choose;
    if(choose==1) chuyentien();
    if(choose==2) giaoDienMenu();
}