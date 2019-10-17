#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"

using namespace std;

BigNumber::BigNumber(string str)
{
	char number[1];
	for (size_t i = str.length(); i != 0;)
	{
		--i;
		*number = str[i];
		vectorNumber_.push_back(atoi(number));
	}
}




BigNumber::~BigNumber()
{
}


void BigNumber::showVector()
{
	vector <int>::iterator it = vectorNumber_.begin();
	cout << "Vector: " << endl;
	while (it != vectorNumber_.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
	

}


