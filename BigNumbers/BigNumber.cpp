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

BigNumber::BigNumber(BigNumber& other)
{
	this->vectorNumber_ = other.vectorNumber_;
}

BigNumber BigNumber::operator+(BigNumber other)
{
	{

		if (this->vectorNumber_.size() < other.vectorNumber_.size())
			this->vectorNumber_.swap(other.vectorNumber_);


		vector<int> vectorResult(this->vectorNumber_.size() + 1, 0);


		for (size_t i = 0; i < this->vectorNumber_.size(); i++)
		{

			if (i < other.vectorNumber_.size())
			{
				vectorResult[i] = this->vectorNumber_[i] + other.vectorNumber_[i] + vectorResult[i];
				vectorResult[i + 1] = vectorResult[i] / 10;
				vectorResult[i] %= 10;
			}
			else
			{
				vectorResult[i] = this->vectorNumber_[i] + vectorResult[i];
				vectorResult[i + 1] = vectorResult[i] / 10;
				vectorResult[i] %= 10;
			}
		}
		if (vectorResult.back() == 0)
			vectorResult.pop_back();

		BigNumber temp(vectorResult);

		return temp;

	}
}

BigNumber BigNumber::operator*(BigNumber other)
{


	if (this->vectorNumber_.size() < other.vectorNumber_.size())
		this->vectorNumber_.swap(other.vectorNumber_);

	vector<int> vectorResult(this->vectorNumber_.size() + other.vectorNumber_.size() + 1, 0);


	for (size_t i = 0; i < other.vectorNumber_.size(); i++)
	{
		for (size_t j = 0; j < this->vectorNumber_.size(); j++)
			vectorResult[i + j] = vectorResult[i + j] + other.vectorNumber_[i] * this->vectorNumber_[j];
	}

	for (size_t i = 0; i < vectorResult.size() - 1; i++)
	{
		vectorResult[i + 1] += vectorResult[i] / 10;
		vectorResult[i] %= 10;
	}

	while (vectorResult.back() == 0)
		vectorResult.pop_back();

	BigNumber temp(vectorResult);

	return temp;

}

BigNumber BigNumber::operator--()
{
	if (vectorNumber_.front() != 0)
		vectorNumber_.front()--;
	else
	{
		vectorNumber_.front() = 9;
		vectorNumber_.at(1)--;
	}
	return *this;
}

BigNumber BigNumber::operator++()
{
	if (vectorNumber_.front() != 9)
		vectorNumber_.front()++;
	else
	{
		vectorNumber_.front() = 0;
		vectorNumber_.at(1)++;
	}
	return *this;
}

BigNumber BigNumber::operator--(int)
{
	BigNumber temp(*this);

	if (this->vectorNumber_.front() != 0)
		this->vectorNumber_.front()--;
	else
	{
		this->vectorNumber_.front() = 9;
		this->vectorNumber_.at(1)--;
	}

	return temp;
}

BigNumber BigNumber::operator++(int)
{
	BigNumber temp(*this);

	if (this->vectorNumber_.front() != 9)
		this->vectorNumber_.front()++;
	else
	{
		this->vectorNumber_.front() = 0;
		this->vectorNumber_.at(1)++;
	}

	return temp;
}

