#pragma once
using namespace std;
class BigNumber
{
public:
	explicit BigNumber(string str);
	explicit BigNumber(vector<int> vectorNum): vectorNumber_(vectorNum) {};
	~BigNumber();

	void showVector();

	BigNumber operator+(BigNumber other)
	{
		
		if (this->vectorNumber_.size() < other.vectorNumber_.size())
		{
			this->vectorNumber_.swap(other.vectorNumber_);
		}
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
		
	};

private:
	std::vector <int> vectorNumber_;
};





