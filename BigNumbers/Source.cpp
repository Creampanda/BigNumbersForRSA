#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
using namespace std;




int main()
{

	BigNumber num1("22");
	num1.showVector();

	BigNumber num2("20");
	num2.showVector();

	num1--;
	num1.showVector();
	--num2;
	num2.showVector();

	num1++;
	num1.showVector();
	++num2;
	num2.showVector();




	return 0;
}

