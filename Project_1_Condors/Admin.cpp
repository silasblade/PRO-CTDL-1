#include "Admin.h"
#include "User.h"
#include "ruttien.h"
#include "ttmapin.h"
#include "lib.h"

using namespace std;


int main() 
{
	//Chỉnh kích cỡ chữ
CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                  
cfi.dwFontSize.Y = 24;              
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); 
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);



//Chỉnh khoảng cách và dấu thập phân
cout << fixed << setw(30);
cout << fixed << setprecision(2);
adminLogin();
	return 0;
}