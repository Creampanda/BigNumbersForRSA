#include "BigNumber.h"
#pragma once
// НОД
BigNumber gcd(BigNumber a, BigNumber b);
// Алгоритм Евклида, для нахождения обратного мультипликативного
void evkl(BigNumber& a, BigNumber& b, BigNumber& d);
// Генерация простых чисел
string getSimple();
string getSimple(int a);
BigNumber getExp(BigNumber & phi);
void encryption(BigNumber & message);