#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream os;

    os.open("test.txt", ios::app);
          os << "\n5" << endl;
    os.close();

}