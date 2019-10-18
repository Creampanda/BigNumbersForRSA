#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
using namespace std;




int main()
{

	BigNumber num1("77214215125154316137");
	num1.showVector();

	BigNumber num2("2125124523156124643162");
	num2.showVector();

	BigNumber num3 = num1 + num2;
	num3.showVector();

	BigNumber num4 = num1 * num2;
	num4.showVector();

	return 0;
}

