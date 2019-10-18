#pragma once
using namespace std;
class BigNumber
{
public:
	explicit BigNumber(const string str);
	explicit BigNumber(const vector<int> vectorNum): vectorNumber_(vectorNum) {};
	~BigNumber();

	void showVector();

	BigNumber(const BigNumber& other) : vectorNumber_(other.vectorNumber_) {};

	BigNumber operator+(const BigNumber& other);

	BigNumber operator*(const BigNumber& other);

	BigNumber & operator--();

	BigNumber & operator++();

	BigNumber operator--(int);
	

	BigNumber operator++(int);


private:
	vector <int> vectorNumber_;
};





