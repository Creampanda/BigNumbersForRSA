#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char num = cin.get();
	vector <int> vectorNumber;
	while (num!='\n')
	{
		vectorNumber.push_back(atoi(&num));
		num = cin.get();
	}
	



	vector <int>::iterator it = vectorNumber.begin();
	while (it != vectorNumber.end())
	{
		cout << *it++ << endl;
	}

	return 0;
}

