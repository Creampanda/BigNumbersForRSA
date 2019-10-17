#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
using namespace std;




int main()
{

	BigNumber num1("15512532895192679275923");
	num1.showVector();

	BigNumber num2("9948249852992958");
	num2.showVector();

	BigNumber num3 = num1 + num2;
	num3.showVector();
	return 0;
}

