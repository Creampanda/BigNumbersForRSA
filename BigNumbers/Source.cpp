#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"
#include "Source.h"
using namespace std;


int main()
{

	BigNumber num1("3");
	
	BigNumber num2("4");


	BigNumber num3 = num1%num2;

	num1.showVector();
	num2.showVector();
	num3.showVector();

	
	return 0;
}

