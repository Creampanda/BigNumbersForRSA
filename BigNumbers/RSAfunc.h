#include "BigNumber.h"
#pragma once
// ���
BigNumber gcd(BigNumber a, BigNumber b);
// �������� �������, ��� ���������� ��������� ������������������
void evkl(BigNumber& a, BigNumber& b, BigNumber& d);
// ��������� ������� �����
string getSimple();
string getSimple(int a);
BigNumber getExp(BigNumber & phi);
void encryption(BigNumber & message);