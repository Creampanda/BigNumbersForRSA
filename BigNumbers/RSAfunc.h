#include "BigNumber.h"
#pragma once
// НОД
BigNumber gcd(BigNumber a, BigNumber b);
// Алгоритм Евклида, для нахождения обратного мультипликативного
void evkl(BigNumber& a, BigNumber& b, BigNumber& d);
// Генерация простых чисел
string getSimple();
string getSimple(int a);
BigNumber getExp(const BigNumber & phi);
void getKeys();
vector <string> getNums(string message);
void decryption(BigNumber d,BigNumber n, BigNumber c);
string getMessage();
void decryption();
void writeIn(BigNumber num);