#include "BigNumber.h"
#pragma once
// ���
BigNumber gcd(BigNumber a, BigNumber b);
// �������� �������, ��� ���������� ��������� ������������������
void evkl(BigNumber& a, BigNumber& b, BigNumber& d);
// ��������� ������� �����
string getSimple();
string getSimple(int a);
BigNumber getExp(const BigNumber & phi);
void encryption(vector <string> symNums);
vector <string> getNums();
void decryption(BigNumber d,BigNumber n, BigNumber c);

void decryption();