#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"

using namespace std;

BigNumber::BigNumber(const string str)
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

void BigNumber::showNumber()
{
	vector <int>::iterator itr = vectorNumber_.end();
	cout << "Number: " << endl;
	while (itr != vectorNumber_.begin())
	{
		cout << *--itr;
	}
	cout << endl;
}





void BigNumber::toPower(int value)
{
	BigNumber temp = (*this);
	for (size_t i = 1; i < value; i++)
	{
		(*this) = temp * (*this);
	}
}



BigNumber BigNumber::operator+(const BigNumber &other)
{
	vector<int> vectorResult;
		if (this->vectorNumber_.size() >= other.vectorNumber_.size())
		{

			vectorResult.resize(this->vectorNumber_.size() + 1, 0);


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
		}
		else
		{

			vectorResult.resize(other.vectorNumber_.size() + 1, 0);


			for (size_t i = 0; i < other.vectorNumber_.size() ; i++)
			{

				if (i < this->vectorNumber_.size())
				{
					vectorResult[i] = this->vectorNumber_[i] + other.vectorNumber_[i] + vectorResult[i];
					vectorResult[i + 1] = vectorResult[i] / 10;
					vectorResult[i] %= 10;
				}
				else
				{
					vectorResult[i] = other.vectorNumber_[i] + vectorResult[i];
					vectorResult[i + 1] = vectorResult[i] / 10;
					vectorResult[i] %= 10;
				}
			}
		}

		if (vectorResult.back() == 0)
			vectorResult.pop_back();

		BigNumber temp(vectorResult);

		return temp;
}

BigNumber BigNumber::operator-(const BigNumber& other)
{
	vector<int> vectorResult(this->vectorNumber_.size(), 0);
	if (*this < other)
	{
		cout << "Substraction impossible" << endl;
		return *this;
	}


	BigNumber tempQ(*this);

	for (size_t i = 0; i < this->vectorNumber_.size(); i++)
	{
		if (i >= other.vectorNumber_.size())
			vectorResult[i] = this->vectorNumber_[i];
		else
		{
			if (this->vectorNumber_[i] < other.vectorNumber_[i])
			{
				size_t j = i + 1;
				while (this->vectorNumber_[j] == 0)
					j++;
				for (size_t q = j; q != i; q--)
				{
					this->vectorNumber_[q]--;
					this->vectorNumber_[q - 1] += 10;
				}
			}

			vectorResult[i] = this->vectorNumber_[i] - other.vectorNumber_[i];
		}
	}
	for (size_t i = 0; i < vectorResult.size() - 1; i++)
	{
		vectorResult[i + 1] += vectorResult[i] / 10;
		vectorResult[i] %= 10;
	}

	while (vectorResult.back() == 0)
		vectorResult.pop_back();

	BigNumber temp(vectorResult);
	*this = tempQ;
	return temp;
}

BigNumber BigNumber::operator*(const BigNumber& other)
{


	vector<int> vectorResult(this->vectorNumber_.size() + other.vectorNumber_.size() + 1, 0);
	if (this->vectorNumber_.size() >= other.vectorNumber_.size())
	{
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
	}
	else
	{
		for (size_t i = 0; i < this->vectorNumber_.size(); i++)
		{
			for (size_t j = 0; j < other.vectorNumber_.size(); j++)
				vectorResult[i + j] = vectorResult[i + j] + other.vectorNumber_[j] * this->vectorNumber_[i];
		}

		for (size_t i = 0; i < vectorResult.size() - 1; i++)
		{
			vectorResult[i + 1] += vectorResult[i] / 10;
			vectorResult[i] %= 10;
		}
	}


	

	while (vectorResult.back() == 0)
		vectorResult.pop_back();

	BigNumber temp(vectorResult);

	return temp;

}

BigNumber BigNumber::operator/(const BigNumber& other)
 {
	if (*this < other)
	{
		vector<int> vectorDIV(1, 0);
		BigNumber temp(vectorDIV);
		return temp;
	}
	if (*this == other)
	{
		vector<int> vectorDIV(1, 1);
		BigNumber temp(vectorDIV);
		return temp;
	}
	vector<int> vectorDIV(0);
	vector<int> vectorDIVresult(0);
	BigNumber temp(vectorDIV);
	
	vector<int>::iterator it = this->vectorNumber_.end();
	while (it!= this->vectorNumber_.begin())
	{
		while (temp < other)
		{
			temp.vectorNumber_.insert(temp.vectorNumber_.begin() ,*--it);
		}

		int t = 0;
		while (temp > other)
		{
			temp = temp - other;
			t++;
		}
		vectorDIVresult.insert(vectorDIVresult.begin(),t);


	}
	BigNumber temp2(vectorDIVresult);

	return temp2;
}

BigNumber BigNumber::operator %(const BigNumber& other)
{
	if (*this < other)
	{
		return *this;
	}
	if (*this == other)
	{
		vector<int> vectorDIV(1,0);
		BigNumber temp(vectorDIV);
		return temp;
	}
	vector<int> vectorDIV(0);
	vector<int> vectorDIVresult(0);
	BigNumber temp(vectorDIV);

	vector<int>::iterator it = this->vectorNumber_.end();
	while (it != this->vectorNumber_.begin())
	{
		while (temp < other)
		{
			temp.vectorNumber_.insert(temp.vectorNumber_.begin(), *--it);
		}

		int t = 0;
		while (temp > other)
		{
			temp = temp - other;
			t++;
		}
		vectorDIVresult.insert(vectorDIVresult.begin(), t);


	}
	return temp;
}

BigNumber BigNumber::operator*(int value)
{
	if (value < 0 || value > 9)
	{
		return *this;
	}
		vector<int> vectorResult(this->vectorNumber_.size() + 2, 0);
				for (size_t i = 0; i < this->vectorNumber_.size(); i++)
					vectorResult[i] = vectorResult[i] + value * this->vectorNumber_[i];

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

BigNumber & BigNumber::operator--()
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

BigNumber & BigNumber::operator++()
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
bool BigNumber::operator==(const BigNumber& other)
{
	if (this->vectorNumber_.size() == other.vectorNumber_.size())
	{
		for (size_t i = this->vectorNumber_.size(); i != 0;)
		{
			--i;
			if (this->vectorNumber_[i] != other.vectorNumber_[i])
				return false;
		}
		return true;
	}
	return false;
}
bool BigNumber::operator!=(const BigNumber& other)
{
	return !(*this == other);
}
bool BigNumber::operator>(const BigNumber& other)
{
	if (this->vectorNumber_.size() > other.vectorNumber_.size())
		return true;
	if (this->vectorNumber_.size() < other.vectorNumber_.size())
		return false;
	for (size_t i = this->vectorNumber_.size(); i !=0;)
	{
		--i;
		if (this->vectorNumber_[i] > other.vectorNumber_[i])
			return true;
		if (this->vectorNumber_[i] < other.vectorNumber_[i])
			return false;
	}
	return false;
}

bool BigNumber::operator>=(const BigNumber& other)
{
	if (this->vectorNumber_.size() > other.vectorNumber_.size())
		return true;
	if (this->vectorNumber_.size() < other.vectorNumber_.size())
		return false;
	for (size_t i = this->vectorNumber_.size(); i != 0;)
	{
		--i;
		if (this->vectorNumber_[i] > other.vectorNumber_[i])
			return true;
		if (this->vectorNumber_[i] < other.vectorNumber_[i])
			return false;
	}
	return true;
}

bool BigNumber::operator<(const BigNumber& other)
{
	if (this->vectorNumber_.size() < other.vectorNumber_.size())
		return true;
	if (this->vectorNumber_.size() > other.vectorNumber_.size())
		return false;
	for (size_t i = this->vectorNumber_.size(); i != 0;)
	{
		--i;
		if (this->vectorNumber_[i] < other.vectorNumber_[i])
			return true;
		if (this->vectorNumber_[i] > other.vectorNumber_[i])
			return false;
	}
	return false;
}

bool BigNumber::operator<=(const BigNumber& other)
{
	if (this->vectorNumber_.size() < other.vectorNumber_.size())
		return true;
	if (this->vectorNumber_.size() > other.vectorNumber_.size())
		return false;
	for (size_t i = this->vectorNumber_.size(); i != 0;)
	{
		--i;
		if (this->vectorNumber_[i] < other.vectorNumber_[i])
			return true;
		if (this->vectorNumber_[i] > other.vectorNumber_[i])
			return false;
	}
	return true;
}


