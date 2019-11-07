#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
using namespace std;

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

void evkl(int a, int b)
{
	static int x = 0;
	static int y = 1;
	int temp;
	if (a == 0)
	{
		return;
	}
	evkl(b%a, a);
	temp = x;
	x = y - (b / a) * x;
	y = temp;
	cout << x << "  " << y << endl;
}

void evkl(BigNumber a, BigNumber b)
{
	static BigNumber x("0");
	static BigNumber y ("1");
	BigNumber temp(x);
	BigNumber nul("0");
	if (a == nul)
	{
		return;
	}
	BigNumber mod = b % a;
	evkl(mod, a);
	temp = x;
	x = y - (b / a) * x;
	y = temp;
	x.showNumber();
	y.showNumber();
}

int main()
{

	evkl(33421, 214421);
	BigNumber num1("33421");
	BigNumber num2("214421");
	evkl(num1, num2);
	/*
	BigNumber num1("-99");
	BigNumber num2("-1");
	BigNumber num3 = num1 - num2;
	num3.showNumber();
	*/
	return 0;
}

