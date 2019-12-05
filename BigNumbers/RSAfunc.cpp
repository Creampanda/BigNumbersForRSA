#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include "RSAfunc.h"

// Функция НОД
BigNumber gcd(BigNumber a, BigNumber b)
{
	BigNumber q = a / b;
	BigNumber r = a % b;
	BigNumber nul("0");
	while (r != nul)
	{
		a = b;
		b = r;
		q = a / b;
		r = a % b;
	}
	return b;
}


static BigNumber x("0");
// Расширенный алгоритм Евклида для нахождения обратной экспоненты
void evkl(BigNumber& a, BigNumber& b, BigNumber& d)
{

	static BigNumber y("1");
	BigNumber temp(x);
	BigNumber nul("0");
	if (a == nul)
	{
		return;
	}
	BigNumber mod = b % a;
	evkl(mod, a, d);
	temp = x;
	x = y - (b / a) * x;
	y = temp;
	d = x;
	if (d.getNegativity())
	{
		d = b + x;
	}
}
//Получить простое число
string getSimple()
{
	vector <string> simpleNumbers = { "11", "13", "17", "19", "23", "29", "31", "37", "41", "43", "47", "53", "59", "61", "67", "71", "83", "89", "97"};
	srand(time(NULL));
	return simpleNumbers[rand() % 19];
}

string getSimple(int a)
{
	vector <string> simpleNumbers = { "11", "13", "17", "19", "23", "29", "31", "37", "41", "43", "47", "53", "59", "61", "67", "71", "83", "89", "97" };
	srand(a);
	return simpleNumbers[rand() % 19];
}

//Получить экспоненту
BigNumber getExp(const BigNumber &phi)
{
	BigNumber exp = phi;
	--exp;
	BigNumber one("1");
	vector <BigNumber> exponents;
	while (exp.getNegativity() == false)
	{
		if (gcd(exp, phi) == one)
			exponents.push_back(exp);
		exp = exp - one;
	} 
	return exponents[rand() % exponents.size()];
}

//Функция генерации ключей
void getKeys()
{
	BigNumber p(getSimple());
	BigNumber q = p;
	while (q == p)
	{
		BigNumber temp(getSimple());
		q = temp;
	}
	BigNumber n = p * q;
	BigNumber phi = --p * --q;
	BigNumber exp = getExp(phi);
	BigNumber d("1");
	evkl(exp, phi, d);
	cout << "Public key (e,n): (";
	exp.showNumber();
	cout << ", ";
	n.showNumber();
	cout << ")" << endl;
	cout << "Private key (d,n): (";
	d.showNumber();
	cout << ", ";
	n.showNumber();
	cout << ")" << endl;

}



//Переводим буквы в цифры для дальнейшего шифрования
vector <string> getNums(string message)
{
	string symbols = "#56789ASDFGHJKLQWERTYUIOPZXCVBNM01234, .!?:КЕНГМИТЗВАПРОЛДЖЯЧСЬБЮХЪЭФЫШЩЙЦУ";
	vector <string> symNums;
	char sym[1];
	for (size_t i = 0; i != message.length(); ++i)
	{
		*sym = message[i];
		for (size_t j = 1; j != symbols.length(); ++j)
		{
			if (*sym == symbols[j])
			{
				symNums.push_back(to_string(j));
			}
		}
	}
	return symNums;
}

void decryption(BigNumber d, BigNumber n,BigNumber c)
{
	BigNumber message = c.modPow(d, n);
	cout << "Text message:" << endl;
	message.showNumber();

}

void decryption()
{
	string str;
	cout << "Enter d:" << endl;
	cin >> str;
	BigNumber d(str);
	cout << "Enter n:" << endl;
	cin >> str;
	BigNumber n(str);
	cout << "Enter c (or 0 to exit):" << endl;
	cin >> str;
	BigNumber c(str);
	BigNumber message = c.modPow(d, n);
	message.showNumber();
};

string getMessage()
{
	ifstream fin;
	fin.open("message.txt");
	string message;
	if (!fin.is_open())
	{
		cout << "Can't open 'message.txt.'" << endl;
	}
	else
	{
		cout << "'message.txt' is opened" << endl;
		getline(fin, message);
	}
	for (size_t i = 0; i < message.length(); ++i)
	{
		message[i] = toupper(message[i]);
	}
	fin.close();
	return message;
}

void writeIn(BigNumber num)
{
	ofstream fout;
	fout.open("ciphertext.txt", ofstream::app);
	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
		fout.open("ciphertext.txt");
	}
	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		vector <short int> vectorNumber = num.getVector();
		vector <short int>::iterator itr = vectorNumber.end();
		if (num.getNegativity())
		{
			fout << "-";
		}
		while (itr != vectorNumber.begin())
		{
			fout << *--itr;
		}
		fout << endl;
	}
	fout.close();
}

void encryption()
{
	string message = getMessage();
	vector <string> messageNums = getNums(message);
	
	
	string number;
	cout << "Enter your public key" << endl;
	cout << "Enter your e: ";
	cin >> number;
	BigNumber e(number);
	cout << "Enter your n: ";
	cin >> number;
	BigNumber n(number);
	ofstream fout;
	fout.open("ciphertext.txt", ofstream::trunc);
	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
		fout.open("ciphertext.txt");
	}
	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		vector <string>::iterator it = messageNums.begin();
		BigNumber previous("0");
		while (it != messageNums.end())
		{
			BigNumber m(*it++);
			BigNumber c = (m + previous).modPow(e, n);
			previous = c;
			vector <short int> vectorNumber = c.getVector();
			vector <short int>::iterator itr = vectorNumber.end();
			if (c.getNegativity())
			{
				fout << "-";
			}
			while (itr != vectorNumber.begin())
			{
				fout << *--itr;
			}
			fout << endl;
		}
		cout << endl << "Your message was successfully encrypted!" << endl;
	}
	fout.close();


}
