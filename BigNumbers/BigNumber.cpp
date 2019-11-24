#include <iostream>
#include <string>
#include <vector>
#include "BigNumber.h"


using namespace std;

BigNumber::BigNumber(const string str)
{
	char number[1];
	if (str[0] == '-')
	{
		negative_ = true;
		for (size_t i = str.length(); i != 1;)
		{
			--i;
			*number = str[i];
			vectorNumber_.push_back(atoi(number));
		}
	}
	else
	{
		negative_ = false;
		for (size_t i = str.length(); i != 0;)
		{
			--i;
			*number = str[i];
			vectorNumber_.push_back(atoi(number));
		}
	}
	
}




BigNumber::~BigNumber()
{
}


void BigNumber::showVector()
{
	vector <short int>::iterator it = vectorNumber_.begin();
	cout << "Vector: " << endl;
	while (it != vectorNumber_.end())
	{
		cout << *it++ << " ";
	}
	cout << endl;
}

void BigNumber::showNumber()
{
	vector <short int>::iterator itr = vectorNumber_.end();
	if (negative_)
	{
		cout << "-";
	}
	while (itr != vectorNumber_.begin())
	{
		cout << *--itr;
	}
	cout << endl;
}





void BigNumber::toPower(size_t value)
{
	BigNumber temp(*this);
	for (size_t i = 1; i < value; i++)
	{
		(*this) = temp * (*this);
	}
}

bool BigNumber::getNegativity()
{
	return negative_;
}

BigNumber BigNumber::modPow(BigNumber grade, BigNumber modul)
{
	
	BigNumber temp("1");
	if (modul == temp)
	{
		return --temp;
	}
	BigNumber zero("0");
	BigNumber one("1");
	while (grade != zero)
	{
		temp = (temp * (*this));
		if (temp > modul)
			temp = temp % modul;
		grade = grade - one;
	}
	return temp;
}



BigNumber & BigNumber::operator=(const BigNumber& other)
{
	if (this != &other)
	{
		this->vectorNumber_ = other.vectorNumber_;
		this->negative_ = other.negative_;
	}
	return *this;
}


BigNumber BigNumber::operator+(const BigNumber &other)
{
	if (this->negative_ && other.negative_ == 0)
	{
		if (*this < other)
		{
			BigNumber temp1 = other;
			BigNumber temp2 = *this;
			temp1.negative_ = false;
			temp2.negative_ = false;
			BigNumber temp = temp1 - temp2;
			temp.negative_ = false;
			return temp;
		}
		BigNumber temp1 = other;
		temp1.negative_ = false;
		BigNumber temp2 = *this;
		temp2.negative_ = false;
		BigNumber temp = temp1 - temp2;
		temp.negative_ = true;
		return temp;
	}
	if (this->negative_==0 && other.negative_)
	{
		if (*this < other)
		{
			BigNumber temp1 = other;
			temp1.negative_ = false;
			BigNumber temp2 = *this;
			temp2.negative_ = false;
			BigNumber temp = temp1 - temp2;
			temp.negative_ = true;
			return temp;
		}
		BigNumber temp1 = other;
		temp1.negative_ = false;
		BigNumber temp2 = *this;
		temp2.negative_ = false;
		BigNumber temp = temp1 - temp2;
		temp.negative_ = false;
		return temp;
	}
	vector<short int> vectorResult;
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

		while (vectorResult.back() == 0)
		{
			if (vectorResult.size() == 1 && vectorResult[0] == 0)
				break;
			vectorResult.pop_back();
		}

		BigNumber temp(vectorResult);

		temp.negative_ = (this->negative_ && other.negative_);
		return temp;
}

BigNumber BigNumber::operator-(const BigNumber& other)
{
	if (this->vectorNumber_[0] == 0 && this->vectorNumber_.size() == 1)
	{
		BigNumber temp = other;
		temp.negative_ = !other.negative_;
		return temp;
	}
	if (this->negative_ && other.negative_ == 0)
	{
		BigNumber temp1 = *this;
		temp1.negative_ = 0;
		BigNumber temp = temp1 + other;
		temp.negative_ = 1;
		return temp;
	}
	if (this->negative_ == 0 && other.negative_)
	{
		BigNumber temp1 = other;
		temp1.negative_ = 0;
		BigNumber temp = *this + temp1;
		temp.negative_ = 0;
		return temp;

	}
	
	

	BigNumber tempQ(*this);
	BigNumber tempOther(other);
	if (*this < other)
	{
		*this = other;
		tempOther = tempQ;
	}

	vector<short int> vectorResult(this->vectorNumber_.size(), 0);

	for (size_t i = 0; i < this->vectorNumber_.size(); i++)
	{
		if (i >= tempOther.vectorNumber_.size())
			vectorResult[i] = this->vectorNumber_[i];
		else
		{
			if (this->vectorNumber_[i] < tempOther.vectorNumber_[i])
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

			vectorResult[i] = this->vectorNumber_[i] - tempOther.vectorNumber_[i];
		}
	}
	for (size_t i = 0; i < vectorResult.size() - 1; i++)
	{
		vectorResult[i + 1] += vectorResult[i] / 10;
		vectorResult[i] %= 10;
	}

	while (vectorResult.back() == 0)
	{
		if (vectorResult.size() == 1 && vectorResult[0] == 0)
			break;
		vectorResult.pop_back();
	}

	*this = tempQ;
	BigNumber temp(vectorResult);
	
	if (*this < other && this->negative_ && other.negative_)
	{
		temp.negative_ = 0;
		return temp;
	}
	if (this->negative_ && other.negative_ && !(*this < other))
	{
		temp.negative_ = 1;
		return temp;
	}
	if (*this < other && (this->negative_ || other.negative_))
	{
		temp.negative_ = 1;
		return temp;
	}
	if (*this < other)
	{
		temp.negative_ = 1;
		return temp;
	}

	return temp;
}

BigNumber BigNumber::operator*(const BigNumber& other)
{


	vector<short int> vectorResult(this->vectorNumber_.size() + other.vectorNumber_.size() + 1, 0);
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
	{
		if (vectorResult.size() == 1 && vectorResult[0] == 0)
			break;
		vectorResult.pop_back();
	}

	BigNumber temp(vectorResult);
	temp.negative_ = (this->negative_ != other.negative_);

	return temp;

}

BigNumber BigNumber::operator/(const BigNumber& other)
 {
	if (*this < other)
	{
		vector<short int> vectorDIV(1, 0);
		BigNumber temp(vectorDIV);
		return temp;
	}
	if (*this == other)
	{
		vector<short int> vectorDIV(1, 1);
		BigNumber temp(vectorDIV);
		return temp;
	}
	vector<short int> vectorDIV(0);
	vector<short int> vectorDIVresult(0);
	BigNumber temp(vectorDIV);
	int counter = 0;
	vector<short int>::iterator it = this->vectorNumber_.end();
	while (it!= this->vectorNumber_.begin())
	{
		counter = 0;
		while (temp < other && it != this->vectorNumber_.begin())
		{
			if(counter!=0)
				vectorDIVresult.insert(vectorDIVresult.begin(), 0);
			
			if (it != this->vectorNumber_.begin())
			{
				temp.vectorNumber_.insert(temp.vectorNumber_.begin(), *--it);
				++counter;
			}
			if (temp.vectorNumber_.back() == 0)
				temp.vectorNumber_.pop_back();
		}

		short int t = 0;
		while (temp >= other)
		{
			temp = temp - other;
			t++;
		}
		vectorDIVresult.insert(vectorDIVresult.begin(),t);


	}
	while (vectorDIVresult.back() == 0)
	{
		if (vectorDIVresult.size() == 1 && vectorDIVresult[0] == 0)
			break;
		vectorDIVresult.pop_back();
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
		vector<short int> vectorDIV(1,0);
		BigNumber temp(vectorDIV);
		return temp;
	}
	vector<short int> vectorDIV(0);
	vector<short int> vectorDIVresult(0);
	BigNumber temp(vectorDIV);
	int counter = 0;
	vector<short int>::iterator it = this->vectorNumber_.end();
	while (it != this->vectorNumber_.begin() )
	{
		counter = 0;
		while (temp < other && it != this->vectorNumber_.begin())
		{
			if (counter!=0)
			{
				vectorDIVresult.insert(vectorDIVresult.begin(), 0);
			}
			temp.vectorNumber_.insert(temp.vectorNumber_.begin(), *--it);
			++counter;
			if (temp.vectorNumber_.back() == 0)
				temp.vectorNumber_.pop_back();
		}

		short int t = 0;
		while (temp >= other)
		{
			temp = temp - other;
			t++;
		}
		vectorDIVresult.insert(vectorDIVresult.begin(), t);


	}
	return temp;
}

BigNumber BigNumber::operator*(short int value)
{
	if (value < 0 || value > 9)
	{
		return *this;
	}
		vector<short int> vectorResult(this->vectorNumber_.size() + 2, 0);
				for (size_t i = 0; i < this->vectorNumber_.size(); i++)
					vectorResult[i] = vectorResult[i] + value * this->vectorNumber_[i];

			for (size_t i = 0; i < vectorResult.size() - 1; i++)
			{
				vectorResult[i + 1] += vectorResult[i] / 10;
				vectorResult[i] %= 10;
			}


			while (vectorResult.back() == 0)
			{
				if (vectorResult.size() == 1 && vectorResult[0] == 0)
					break;
				vectorResult.pop_back();
			}

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


