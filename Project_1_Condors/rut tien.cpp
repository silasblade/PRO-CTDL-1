#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime> 
#include <vector>
#include <fstream>
using namespace std;

/*void lichsugiaodich(int sodu) {
	
	string luu = name + "\n" + sodu + "\n" + tienrut;
	time_t now = time(0);
	
}*/
void ruttien() {
	ifstream ifs("C:\\Users\\Admin\\Documents\\GitHub\\PRO-CTDL-1\\Project_1_Condors\\ID_User\\[ID].txt");
	vector<string> lines;
	string line;
	while (getline(ifs, line)){
        lines.push_back(line);
    }
	int sodu = atoi(lines[9].c_str());
	sodu += 20000000;
	cout << "\t \t \t\t\t\ RUT TIEN\n";
	cout << "\n \t \t Nhap so tien ban muon rut: ";
	int tienrut;
	cin >> tienrut;
	system("cls");
	if (tienrut < 50000) {
		cout << "\t \t So tien rut khong hop le moi nhap lai!!!";
		Sleep(4*1000);
		system("cls");
		ruttien();
	} else if (sodu - tienrut < 50000) {
		cout << "\t \t Con do ngheo khi nay tien du dau ma rut!!!";
		Sleep(4*1000);
		system("cls");
		ruttien();
		/*int thoat;
		cout << "Quay lai Menu(nhan phim 0 de quay lai) : ";cin >> thoat;
		if (thoat == 0) {
			system("CLS");
			userMenu();
		}*/
	} else if (tienrut % 50000 != 0) {
		cout << "\t \t So tien phai la boi so cua 50000!!!";
		Sleep(4*1000);
		system("cls");
		ruttien();
	} else {
		Sleep(2*1000);
		cout << "\t \t Rut tien thanh cong!!! \n";
		sodu -= tienrut;
		cout << "\t \t So tien con lai la: " << sodu;
		//userMenu();
		
	}
	ifs.close();
	
}

