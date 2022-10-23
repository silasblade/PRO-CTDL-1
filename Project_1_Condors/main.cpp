#include "Admin.h"
#include "User.h"
#include "ruttien.h"
#include "ttmapin.h"
#include "lib.h"

using namespace std;


int main() 
{

	static CONSOLE_FONT_INFOEX  fontex;
    fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetCurrentConsoleFontEx(hOut, 0, &fontex);
    fontex.FontWeight = 400;
    fontex.dwFontSize.X = 20;
    fontex.dwFontSize.Y = 20;

    SetCurrentConsoleFontEx(hOut, 2, &fontex);
cout << fixed << setw(30);
cout << fixed << setprecision(2);
string chon;
do
{
cout << "\t\t\t\t* * * * * * * * * * * * * * *" << endl;
cout << "\t\t\t\t*  Chon chuc nang dang nhap *" << endl;
cout << "\t\t\t\t*  1. Dang nhap Admin       *" << endl;
cout << "\t\t\t\t*  2. Dang nhap User        *" << endl;
cout << "\t\t\t\t* * * * * * * * * * * * * * *" << endl;
cout << "\t\t\t\t*  Chon: ";    cin >> chon;
system("cls");
}
while (chon != "1" && chon != "2");      

if(chon == "1") adminLogin();
else if(chon == "2") giaoDienDangNhapUser();
	return 0;
}