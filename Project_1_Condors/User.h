#pragma once
#include "lib.h"
#include "Admin.h"

string currentuser;

#include "ruttien.h"
#include "ttmapin.h"


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
void chuyentien();
void xemtt();
void xemgd();
void doimapin();

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

void giaoDienDangNhapUser() 
{
    system("cls");
    //Nạp file thẻ từ
	string id[100];
    string pin[100];
    int i=0;
    ifstream is("TheTu.txt");
	getline(is, id[0]);
	getline(is, pin[0]);
	i++;

    while(!pin[i-1].empty())
    {
        getline(is, id[i]);
        getline(is, pin[i]);
        i++;
    }
    is.close();
 
        string ID, PIN; //Giao diện đăng nhập
        cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * *\n";
        cout << "\t\t\t\t*             DANG NHAP USER            *\n";
        cout << "\t\t\t\t* * * * * * * * * * * * * * * * * * * * *\n";
        cout << "\t\t\t\tID : "; cin >> ID;
        int dem=0;
        int sodem=0;

        //Kiểm tra ID nhập có tồn tại không
        for(int j=0; j<i-1;j++)
        {
              if(ID==id[j]) {dem++; sodem=j;}
        }

        if (dem==0)
        {
            cout << "\t\t\t\tID nguoi dung khong ton tai." << endl;
            cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
            cout << "\t\t\t\t";
            system("pause");
            giaoDienDangNhapUser();
        }

        //ID tồn tại, nạp file người dùng
        ifstream is2("ID_User/" + ID + ".txt");
            string tt[10];
            int khoa;
            for(int j=0; j<4; j++)
            {
                getline(is2, tt[j]);
            }
            is2 >> khoa;
            is2.close();
       
        cout << "\t\t\t\tPIN : "; Pass(PIN);
        
        //Kiểm tra tài khoản bị khóa
        if(khoa==3)
        {
            cout << endl;
            cout << "\t\t\t\tTai khoan cua ban da bi khoa." << endl;
            cout << "\t\t\t\tBam phim bat ky de ket thuc." << endl;
            cout << "\t\t\t\t";
            system("pause");
            exit(0);
            giaoDienDangNhapUser();
        }

        //Kiểm tra PIN nhập đúng, nhập sai thì sẽ ghi nhận vào file người dùng
        if(pin[sodem]!=PIN)
        {
            khoa++;
            ofstream os("ID_User/" + ID + ".txt");
            for(int j=0; j<4; j++)
            {
                os << tt[j] << endl;
            }
            os << khoa;
            os.close();

            cout << endl;
            cout << "\t\t\t\tBan nhap sai mat khau." << endl;
            cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
            cout << "\t\t\t\t";
            system("pause");
            giaoDienDangNhapUser();
        }

        currentuser=ID;
        giaoDienMenu();
}




void Thoat() {
    giaoDienDangNhapUser();
}

#include "ruttien.h"

void giaoDienMenu() //Giao diện Menu
{
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
        xemtt();
    }
    if (a == 2) 
    {
        ruttien();
    }
    if (a == 3) {
        chuyentien();
    }
    if (a == 4) {
        xemgd();
    }
    if (a == 5) {
        doimapin();
    }
    if (a == 6) {
        giaoDienDangNhapUser();
    }
}

#include "ruttien.h"
