#include "Admin.h"
#include "User.h"
#include "ruttien.h"
#include "ttmapin.h"
#include "lib.h"

using namespace std;


int main() 
{

CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                  
cfi.dwFontSize.Y = 24;              
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); 
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

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