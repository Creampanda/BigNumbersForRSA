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

int main()
{
	evkl(3, 9167368);
	cout << -3055789 + 9167368;
	return 0;
}

