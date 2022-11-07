#include <bits/stdc++.h>

void doiMaPin(string id)
{
	string pin;
	ifstream ipin("TheTu.txt");
	string ID[100];
	string PW[100];
	int i = 0;
	while (!ipin.eof()) 
	{
		getline(ipin, ID[i]);
		getline(ipin, PS[i]);
		
		if (ID[i] == id)
		{
			cout << ID[i] << endl;
			cout << "New Pin: ";
			cin >> pin;
			PS[i] = pin;
		}
		i++;
	}
	ipin.close();
	ofstream os("TheTu.txt");
	int j = 0;
	while (j <= i)
	{
		os << ID[j] << endl << PW[j] << endl;
		j++;
	}
}
