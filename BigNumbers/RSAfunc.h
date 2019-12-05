#include "BigNumber.h"
#pragma once
// ���
BigNumber gcd(BigNumber a, BigNumber b);
// �������� �������, ��� ���������� ��������� ������������������
void evkl(BigNumber& a, BigNumber& b, BigNumber& d);
// ��������� ������� �����
string getSimple();
string getSimple(int a);
// �������� ����������
BigNumber getExp(const BigNumber & phi);
// ������� ��������� ������
void getKeys();
//������� �������� ���� � �����
vector <string> getNums(string message);
void decryption(BigNumber d,BigNumber n, BigNumber c);
string getMessage();
void decryption();
//�������� ����� � ����
void writeIn(BigNumber num);
void encryption();