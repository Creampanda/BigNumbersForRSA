#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
using namespace std;


int main()
{

	BigNumber num1("666");
	
	BigNumber num2("2014");
	BigNumber num3 = num1.modPow(777,"2014");

	//BigNumber num3 = num2 % num1;

	num1.showNumber();
	num3.showNumber();
	
	

	return 0;
}

