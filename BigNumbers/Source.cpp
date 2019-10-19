#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
#include "Source.h"
using namespace std;


int main()
{

	BigNumber num1("94141361343164366299");
	
	BigNumber num2("10051251234114363646410");

	BigNumber num3 = num2-(num1);

	num1.showVector();
	num2.showVector();
	num3.showVector();
	return 0;
}

