#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
#include "RSAfunc.h"


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

string getSimple()
{
	vector <string> simpleNumbers = { "3", "5", "7", "11", "13", "17", "19", "23", "29", "31", "37", "41", "43", "47", "53", "59", "61", "67", "71", "83", "89", "97"};
	srand(time(NULL));
	return simpleNumbers[rand() % 22];
}

string getSimple(int a)
{
	vector <string> simpleNumbers = { "3", "5", "7", "11", "13", "17", "19", "23", "29", "31", "37", "41", "43", "47", "53", "59", "61", "67", "71", "83", "89", "97" };
	srand(a);
	return simpleNumbers[rand() % 22];
}

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

//Ôóíêöèÿ øèôðîâàíèÿ
void encryption(vector <string> symNums)
{
	ofstream fout;
	fout.open("ciphertext.txt");
	BigNumber p(getSimple());
	BigNumber q = p;
	while (q == p)
	{
		BigNumber temp(getSimple());
		q = temp;
	}
	cout << "Your number p:" << endl;
	p.showNumber();
	cout << "Your number q:" << endl;
	q.showNumber();
	BigNumber n = p * q;
	cout << "Your number n:" << endl;
	n.showNumber();
	BigNumber phi = --p * --q;
	cout << "Your number phi:" << endl;
	phi.showNumber();
	++p;
	++q;
	BigNumber exp = getExp(phi);
	cout << "Your number exp:" << endl;
	exp.showNumber();
	BigNumber d("1");
	evkl(exp, phi, d);
	cout << "Your number d:" << endl;
	d.showNumber();
	vector <string>::iterator it = symNums.begin();
	BigNumber previous("0");
	while (it != symNums.end())
	{
		BigNumber m(*it++);
		cout << "m:";
		m.showNumber();
		BigNumber c = m.modPow(exp, n);
		previous = c + m;
		/*cout << "Your ciphertext:" << endl;
		c.showNumber();
	}*/
};

//Ïåðåâîäèì áóêâû â öèôðû äëÿ äàëüíåéøåãî øèôðîâàíèÿ
vector <string> getNums() 
{
	ifstream fin("message.txt");
	if (!fin.is_open())
	{
		cout << "Cant open" << endl;
	}
	string message;
	getline(fin, message);
	string symbols = "#56789ASDFGHJKLQWERTYUIOPZXCVBNM01234, .!?:ÊÅÍÃÌÈÒÇÂÀÏÐÎËÄÆß×ÑÜÁÞÕÚÝÔÛØÙÉÖÓ";
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
	fin.close();
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