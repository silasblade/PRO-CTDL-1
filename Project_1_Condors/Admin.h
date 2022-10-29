#pragma once
#include"lib.h"
#include"lock.h"

using namespace std;


void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

void moKhoaTaiKhoan();
void adminMenu();
void adminLogin();

//Chuyển đổi mật khẩu thành dấu *
void Pass(string &password)
{
	setcolor(14);
	int ch;
	int i=0;
    while(ch!=13)
    {
		ch=getch();
       
        if(ch==8 && i>0)
        {
		i--;
        cin.clear();
        cout << '\b';
        cout << " ";
        cout << '\b';
		password.pop_back();
        }

        else if(ch!=8 && ch!=13)
		{
		i++;
        cout << "*";
		password.push_back(ch);
		}	
    }
}



void listUser() //Xuất danh sách người dùng
{
	system("cls");

	//Nạp file thẻ từ
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

    //Giao diện xuất tất cả thẻ từ
	setcolor(11);
	cout << "\t\t\t\t**** Thong tin cac nguoi dung ****" << endl;
	cout << endl;
    
	setcolor(14);
	for(int k=1; k<i; k++)
	{
		cout << "\t\t\t\tUser " << k << "  :" << user[k-1] << endl;
		cout << "\t\t\t\tPIN     :" << pin[k-1] << endl;
		cout << endl;
	}


    setcolor(10);
	cout << "\t\t\t\tNhan phim bat ky de quay lai menu." << endl;
	cout << "\t\t\t\t";
	system("pause");
	adminMenu();

}

void listdel() //Danh sách người dùng
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
	setcolor(11);
	cout << "\t\t\t\tDanh sach nguoi dung: " << endl;
	cout << endl;
    
	setcolor(14);
	for(int k=1; k<i; k++)
	{
		cout << "\t\t\t\tUser " << k << "  :" << user[k-1] << endl;
		cout << "\t\t\t\tPIN     :" << pin[k-1] << endl;
		cout << endl;
	}
}

void addNewUser() //Thêm người dùng
{
	system("cls");
    //Nạp mảng chuỗi các thông tin từ file
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

    //Nhập ID mới
	setcolor(11);
	cout << "\t\t\t\t**** Them nguoi dung moi ****" << endl;
	string id;
	setcolor(14);
	cout << "\t\t\t\tTao ID (14 chu so): ";
	cin >> id;
    
    for(int k=0; k<i-1; k++)
	{
		if(id==u[k])
		{    
			setcolor(12);
			cout << "\t\t\t\tID da ton tai, vui long nhap lai. Nhan Enter de tiep tuc." << endl;
			cout << "\t\t\t\t";
			system("pause");
			addNewUser();
		}
	}

	if(id.size()!=14)
		{
			setcolor(12);
			cout << "\t\t\t\tID nhap khong dung yeu cau. Bam phim bat ky de nhap lai." << endl;
			cout << "\t\t\t\t";
			system("pause");
			addNewUser();
		}
    
	for(int k=0; k<id.size(); k++)
	{
		if(!isdigit(id[k]))
		{
			setcolor(12);
			cout << "\t\t\t\tID chi nhap chu so. Vui long nhap lai." << endl;
			cout << "\t\t\t\t";
			system("pause");
			addNewUser();
		}
	}


    //Khởi tạo mã PIN và nhập tên người dùng
	string pin;
	pin="123456";
	cout << "\t\t\t\tNhap ten nguoi dung: ";
	string ten;
	cin.ignore();
	getline(cin, ten);
	string tien="50000";
	string donvi = "VND";
	int solannhapsai = 0;

    //Cập nhật thẻ từ
    ofstream TheTu("TheTu.txt", ios_base::app);
	TheTu << id << endl;
	TheTu << pin << endl;
    TheTu.close();

    //Lưu dữ liệu người dùng
	ofstream NewUser("ID_User/" + id + ".txt");
	NewUser << id << endl;
	NewUser << ten << endl;
	NewUser << tien << endl;
	NewUser << donvi << endl;
	NewUser << solannhapsai << endl;
    NewUser.close();
    
	//Lưu dữ liệu lịch sử
    time_t now = time(0);
    char* dt = ctime(&now);
    string lsmoi="LichSu";
	lsmoi=lsmoi+id;
	ofstream newLS("ID_User/" + lsmoi + ".txt");
	newLS << dt;
	newLS << id << endl;
	newLS << ten << endl;
	newLS << "50000 VND" << endl;
	newLS << "<TAO TAI KHOAN>" << endl;
	newLS << "\n";
	newLS.close();

    //Trở về sau khi hoàn tất sử dụng
    cout << endl;
	setcolor(10);
	cout << "\t\t\t\tNguoi dung duoc tao thanh cong!!!" << endl;
	cout << "\t\t\t\tNhan phim bat ky de tro lai menu." << endl;
	cout << "\t\t\t\t";
	system("pause");
    adminMenu();
}

void deleteUser() //Xóa người dùng
{
	system("cls");
	//Hiện danh sách
	listdel();
	//Nạp dữ liệu thẻ từ
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

    //Nhập ID cần xóa và các trường hợp nhập sai
    int checkdel=0;
	int numdel;
	string id;
	setcolor(11);
	cout << "\t\t\t\tNhap id can xoa: "; cin >> id;
	for(int k=0; k<i-1; k++)
	{
		if(id==user[k]) {checkdel++; numdel=k;}
	}

    if(checkdel==0)
	{
		setcolor(12);
		cout << "\t\t\t\tID ban nhap khong dung." << endl;
		cout << "\t\t\t\tBam phim bat ky de nhap lai." << endl;
		cout << "\t\t\t\t";
		system("pause");
		deleteUser();
	}
    
	//Xóa file người dùng và file lịch sử
	string addres="ID_User/";
	addres=addres+id+".txt";
	string lichsu="ID_User/LichSu";
	lichsu=lichsu+id+".txt";
	const char *c = addres.c_str();
	const char *d = lichsu.c_str();
	remove(c);
    remove(d);
	
	//Cập nhật lại thẻ từ
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
    
	//Kết thúc chức năng
	cout << endl;
	setcolor(10);
	cout << "\t\t\t\tNguoi dung duoc xoa thanh cong!!!" << endl;
	cout << "\t\t\t\tNhan phim bat ky de tro lai menu." << endl;
	cout << "\t\t\t\t";
	system("pause");
    adminMenu();
}

void adminMenu() //Menu dành cho admin
{
	system("cls");
	setcolor(11);
	cout << "\t\t\t\t************************* Menu ************************\n";
	setcolor(14);
	cout << "\t \t \t\t\t\t1. Xem danh sach tai khoan.\n";
	cout << "\t \t \t\t\t\t2. Them tai khoan.\n";
	cout << "\t \t \t\t\t\t3. Xoa tai khoan.\n";
	cout << "\t \t \t\t\t\t4. Mo khoa tai khoan.\n";
	cout << "\t \t \t\t\t\t5. Thoat.\n";
	setcolor(11);
	cout << "\t\t\t\t*******************************************************\n";
	setcolor(9);
	cout << "\t \t\t\t\t\t Chon chuc nang: ";
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

void adminLogin() //Màn hình đăng nhập admin
{
	system("cls");
    setcolor(11);
	//Nạp file admin
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
	setcolor(14);
	cout << "\n\t\t\t\tUser: "; cin >> id;
	cout << "\n\t\t\t\tPassword: ";
	setcolor(11);
	
    Pass(password);
    //Xác nhận mật khẩu đúng
    for(int j=0; j<i; j++)
    {
       if(id==user[j] && password==pin[j]) adminMenu();
    }

	cout << endl;
	setcolor(12);
	cout << "\t\t\t\tNhap sai mat khau hoac tai khoan, vui long nhap lai." << endl;
	cout << "\t\t\t\t";
	system("pause");
	adminLogin();
	
	
}
