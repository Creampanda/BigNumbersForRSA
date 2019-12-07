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
string getMessage();
//�������� ����� � ����
void writeIn(BigNumber num);
//������� ����������
void encryption();
//������� ����������
void decryption();
void createNewMessage();