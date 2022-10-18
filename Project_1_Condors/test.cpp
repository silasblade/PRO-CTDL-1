#include <fstream>

#include<iostream>

using namespace std;
int main() {
ifstream myfile;
string ad="123";
myfile.open("ID_User/" + ad +  ".txt");
if(!myfile) {
cout<<"file exists";
   } 
   else {
cout<<"file doesn't exist";
   }
}