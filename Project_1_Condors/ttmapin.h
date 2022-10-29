#pragma once
#include "lib.h"
#include "User.h"
using namespace std;

void giaoDienMenu();

void xemtt() // Xem thông tin thẻ từ
{
  system("cls");
  cout  << "\t\t\t\t\t**** Thong tin nguoi dung ****" << endl;

  //Nạp file người dùng
  ifstream is("ID_User/" + currentuser +".txt");
  string x[5];
  for(int i=0; i<4; i++)
  {
    getline(is, x[i]);
  }
  is.close();
  
  //Hiển thị các thông tin trong file
  cout << "\t\t\t\tID: " << x[0] << endl;
  cout << "\t\t\t\tTen nguoi dung: " << x[1] << endl;
  cout << "\t\t\t\tSo du: " << x[2] << " " << x[3] << endl;
  cout << endl;

  cout << "\t\t\t\tBam phim bat ky de tro lai menu." << endl;
  cout << "\t\t\t\t";
  system("pause");
  giaoDienMenu();
}

void xemgd()
{
  system("cls");
  cout  << "\t\t\t\t\t**** Thong tin giao dich ****" << endl;
  
  //Nạp file lịch sử giao dịch
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

  //Xuất các thông tin trong file
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

  //Nạp file thẻ từ
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

  //Nhập mã pin cần đổi
  cout << "\t\t\t\t**** Doi maPIN ****" << endl;
  cout << "\t\t\t\tNhap ma pin moi (6 so): ";
  string newpin;
  string newpinconfirm;
  cin >> newpin;
  
//Điều kiện nhập mã PIN
  if(newpin.size()!=6)
  {
    cout << "\t\t\t\tBan nhap khong dung." << endl;
    cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
    cout << "\t\t\t\t";
    system("pause");
    doimapin();
  }

  //Kiểm tra nếu người dùng nhập sai
  int checkdigit=0;
  for(int o=0; o<newpin.size(); o++)
  {
    if(!isdigit(newpin[0])) checkdigit++;
  }
  
  if(checkdigit!=0)
  {
    cout << "\t\t\t\tMa PIN chi duoc nhap so." << endl;
    cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
    system("pause");
    doimapin();
  }
  
  //Nhập lại
  cout << "\t\t\t\tNhap lai ma PIN moi: ";
  cin >> newpinconfirm;

  //Kiểm tra PIN nhập đúng
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
    cout << "\t\t\t\t";
    system("pause");
    doimapin();
  }
  
  cout << "\t\t\t\tBan da doi ma PIN thanh cong." << endl;
  cout << "\t\t\t\tBam phim bat ky de tro lai menu." << endl;
  cout << "\t\t\t\t";
  system("pause");
  giaoDienMenu();

}