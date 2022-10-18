#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include "userreal.h"
using namespace std;

void giaoDienMenu();
void xemtt()
{
  system("cls");
  cout  << "\t\t\t\t\t**** Thong tin nguoi dung ****" << endl;
  ifstream is("ID_User/" + currentuser +".txt");
  string x[5];
  for(int i=0; i<4; i++)
  {
    getline(is, x[i]);
  }
  is.close();

  cout << "\t\t\t\tID: " << x[0] << endl;
  cout << "\t\t\t\tTen nguoi dung: " << x[1] << endl;
  cout << "\t\t\t\tSo du: " << x[2] << " " << x[3] << endl;
  cout << endl;
  cout << "\t\t\t\tBam phim bat ky de tro lai menu." << endl;
  system("pause");
  giaoDienMenu();
}

void xemgd()
{
  system("cls");
  cout  << "\t\t\t\t\t**** Thong tin giao dich ****" << endl;
  string file="LichSu";

  file=file+currentuser;
  ifstream is("ID_User/" + file +".txt");
  string x[100];
  int i=0;
  getline(is, x[0]);
  i++;
  getline(is, x[1]);
  i++;
  while(!x[i-1].empty() || !x[i-2].empty())
  {
    getline(is, x[i]);
    i++;
  }
  is.close();

  for(int j=0; j<i; j++)
  {
    cout << "\t\t\t\t" << x[j] << endl;
  }

  cout << "\t\t\t\tBam phim bat ky de tro lai menu." << endl;
  cout << "\t\t\t\t";
  system("pause");
  giaoDienMenu();
}
  
void doimapin()
{
  system("cls");
  ifstream is;
  string id[100];
  string pin[100];
  is.open("TheTu.txt");
  int i=0;
  getline(is, id[i]);
  getline(is, pin[i]);
  i++;
  while(!pin[i-1].empty())
  {
    getline(is, id[i]);
    getline(is, pin[i]);
    i++;
  }
  is.close();
  cout << "\t\t\t\t**** Doi maPIN ****" << endl;
  cout << "\t\t\t\tNhap ma pin moi: ";
  string newpin;
  string newpinconfirm;
  cin >> newpin;
  cout << "\t\t\t\tNhap lai ma PIN moi: ";
  cin >> newpinconfirm;

  if(newpin==newpinconfirm)
  {
      for(int j=0; j<i; j++)
      {
        if(currentuser==id[j])
        pin[j]=newpin;
      }
      ofstream os("TheTu.txt");
      for(int k=0; k<i-1; k++)
      {
        os << id[k] << endl;
        os << pin[k] << endl;
      }
      os.close();
  }

  else
  {
    cout << "\t\t\t\tBan nhap khong dung." << endl;
    cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
    system("pause");
    doimapin();
  }
  
  cout << "\t\t\t\tBBan da doi ma PIN thanh cong." << endl;
  cout << "\t\t\t\tBam phim bat ky de tro lai menu." << endl;
  cout << "\t\t\t\t";
  system("pause");
  giaoDienMenu();

}