#pragma once
using namespace std;
class BigNumber
{
public:
	explicit BigNumber(const string str);
	explicit BigNumber(const vector<short int> vectorNum, const bool negative = 0): vectorNumber_(vectorNum), negative_(negative) {};
	~BigNumber();

	BigNumber(const BigNumber& other) : vectorNumber_(other.vectorNumber_), negative_(other.negative_) {};

	BigNumber & operator=(const BigNumber& other);

	BigNumber operator+(const BigNumber& other);
	BigNumber operator-(const BigNumber& other);


	BigNumber operator*(const BigNumber& other);
	BigNumber operator/(const BigNumber& other);

	BigNumber operator %(const BigNumber& other);

	BigNumber operator*(short int value);

	BigNumber & operator--();

	BigNumber & operator++();

	BigNumber operator--(int);
	
	BigNumber operator++(int);
	
	bool operator==(const BigNumber& other);
	bool operator!=(const BigNumber& other);
	bool operator>(const BigNumber& other);
	bool operator>=(const BigNumber& other);
	bool operator<(const BigNumber& other);
	bool operator<=(const BigNumber& other);

	void showVector();
	void showNumber();

	void toPower(size_t value);

	BigNumber modPow(short int exp, const string modul);

private:
	vector <short int> vectorNumber_;
	bool negative_;
};





