#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main()
{
    int ch;
    string pass;
    ch=getch();
    while(ch!=13)
    {
        pass.push_back(ch);
        if(ch==8)
        {
        cin.clear();
        cout << '\b';
        cout << " ";
        cout << '\b';
        }
        else
        cout << "*";
        ch=getch();
    }
}