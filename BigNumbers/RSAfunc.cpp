#include <iostream>
#include <string>
#include <vector>
#include <time.h>
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

BigNumber getExp(BigNumber &phi)
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

void encryption(BigNumber & message)
{
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
	BigNumber m = message;
	cout << "Your message:" << endl;
	m.showNumber();
	BigNumber c = m.modPow(exp, n);
	cout << "Your ciphertext:" << endl;
	c.showNumber();
	BigNumber x = c.modPow(d, n);
	cout << "Your message:" << endl;
	x.showNumber();
};