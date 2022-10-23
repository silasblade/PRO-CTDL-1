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
cout << fixed << setw(30);
cout << fixed << setprecision(2);
adminLogin();
	return 0;
}