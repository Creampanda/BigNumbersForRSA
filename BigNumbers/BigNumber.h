#pragma once
using namespace std;
class BigNumber
{
public:
	explicit BigNumber(string str);
	explicit BigNumber(vector<int> vectorNum): vectorNumber_(vectorNum) {};
	~BigNumber();

	void showVector();

	BigNumber(BigNumber& other);

	BigNumber operator+(BigNumber other);

	BigNumber operator*(BigNumber other);

	BigNumber operator--();

	BigNumber operator++();

	BigNumber operator--(int);
	

	BigNumber operator++(int);


private:
	vector <int> vectorNumber_;
};





