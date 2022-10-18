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

string currentuser;

#include "ruttien.h"



using namespace std;
int u = 1;


class UserInfo {
private:
    string id, name;
    int money;
    string type;
public:
    void setId(string _id) {
        id = _id;
    }
    void setName(string _name) {
        name = _name;
    }
    void setType(string _type) {
        type = _type;
    }
    void setmoney(int _money) {
        money = _money;
    }
    string getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getType() {
        return type;
    }
    int getMoney() {
        return money;
    }
    ~UserInfo();
    friend ostream& operator<<(ostream& os, UserInfo a) {
        os << a.id << "\n" << a.name << "\n" << a.money << "\n" << a.type;
        return os;
    }
};
void ruttien();
void giaoDienMenu();

bool login_validation(string ID, string pass) 
{
    bool valid = false;
    string getID, getPass;
    ifstream data;
    data.open("TheTu.txt");
    while (getline(data, getID) )
    { 
        getline(data, getPass);
        if (ID == getID && pass == getPass) {
            valid = true;
            break;
        }
    }
    data.close();
    if(valid){
        return 1;
    }
    else{
        return 0;
    }
    
}

void giaoDienDangNhapUser() {
    string ID, PIN;
    int dem = 0;
    
    bool validateLogin;
    do{
        system("cls");
        // sleep_for(10ns);
        cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * *\n";
        cout << "\t\t\t\t*             DANG NHAP USER            *\n";
        cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * *\n";
        cout << "\t\t\t\tID : "; cin >> ID;
        cout << "\t\t\t\tPIN : "; Pass(PIN);
        validateLogin = login_validation(ID,PIN);

        if(validateLogin)
        {
            currentuser=ID;
            giaoDienMenu();
        }
        else {
            dem++;
            cout << "Ban da nhap sai tai khoan, hoac ma PIN. Vui long dang nhap lai\n";
            if (dem == 3) {
                cout << "Tai khoan ban da bi khoa\n";
			    exit(0);
            }
            system("pause");
        }

    }while(!validateLogin);
}



// UserInfo arrInfo[10000];
// void layDuLieuThongTinUser() {
//     ifstream Info;
//     Info.open("ID.txt");
//     string ID;
//     string name;
//     int money;
//     string type;
//     while(!Info.eof()) {
//         Info >> ID;
//         getline(Info, name);
//         // Info.ignore();
//         Info >> money;
//         Info >> type;
//         UserInfo p(ID, name, money, type);
//         arrInfo[u] = p;
//         u++;
//     }
//     Info.close();
// }
// void xemThongTinUser() {
//     layDuLieuThongTinUser();
//     for (int i = 0; i < u; ++i) {
//         cout << arrInfo[i] << endl;
//     }
// }



void chuyenTien() {
    
}
void xemNoiDungGiaoDich() {
    
}
void doiMaPin() {
    
}


void Thoat() {
    giaoDienDangNhapUser();
}

#include "ruttien.h"

void giaoDienMenu() {
    system("cls");
    cout << "\t\t\t\t";
    cout << "***************MENU*****************\n";
    cout << "\t\t\t\t      1. Xem thong tin tai khoan\n";
    cout << "\t\t\t\t      2. Rut tien\n";
    cout << "\t\t\t\t      3. Chuyen tien\n";
    cout << "\t\t\t\t      4. Xem noi dung giao dich\n";
    cout << "\t\t\t\t      5. Doi ma pin\n";
    cout << "\t\t\t\t      6. Thoat\n";
    cout << "\t\t\t\t************************************\n";
    cout << "\t\t\t\tChon chuc nang: "; int a; cin >> a;
    if (a == 1) {
        // xemThongTinUser();
    }
    if (a == 2) 
    {
        ruttien();
    }
    if (a == 3) {
        // chuyenTien();
    }
    if (a == 4) {
        // xemNoiDungGiaoDich();
    }
    if (a == 5) {
        // doiMaPin();
    }
    if (a == 6) {
        giaoDienDangNhapUser();
    }
}

#include "ruttien.h"
