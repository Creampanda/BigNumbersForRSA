#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
#include "Source.h"
using namespace std;


int main()
{
	BigNumber num1("21421");

	BigNumber num2("4124201");



	BigNumber num3 = (num1 +num2);
	BigNumber num4 = (num1 * num2);
	num1.showVector();
	num2.showVector();
	num3.showVector();
	num4.showVector();


	return 0;
}

