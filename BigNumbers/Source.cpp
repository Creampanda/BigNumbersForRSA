#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "RSAfunc.h"


int main()
{



	vector <string> symNums = getNums();
	vector <string>::iterator it = symNums.begin();
	while (it != symNums.end())
	{
		cout << *it++ << endl;
	}
	encryption(symNums);



	
	
	return 0;
}

-