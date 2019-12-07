#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "RSAfunc.h"

extern BigNumber x;
int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		cout << "------------------------------------------------" << endl;
		cout << "Choose any action: " << endl;
		cout << "1) Create a new message" << endl;
		cout << "2) Create a pair of keys" << endl;
		cout << "3) Encrypt message (message.txt)" << endl;
		cout << "4) Decrypt ciphertext (ciphertext.txt)" << endl;

		cout << "0) Exit" << endl;
		int answer = -1;
		bool bFail = true;
		while (answer < 0 || answer > 4 || bFail == true)
		{
			cout << "Enter the number: ";
			cin >> answer;
			bFail = cin.fail();
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "------------------------------------------------" << endl << endl;
		BigNumber zero("0");
		switch (answer)
		{
		case 1:
			createNewMessage();
			break;
		case 2:
			if (x != zero)
			{
				cout << "You've already got keys!" << endl;
				break;
			}
			getKeys();
			break;
		case 3:
			encryption();
			break;
		case 4:
			decryption();
			break;
		case 0:
			exit(0);
		}
	}
	
	return 0;
}


/*
443
164
598
877
443
164
598
877
443
164
598
877
443
164
598
877
*/
