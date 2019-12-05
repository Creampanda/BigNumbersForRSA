#include "BigNumber.h"
#pragma once
// НОД
BigNumber gcd(BigNumber a, BigNumber b);
// Алгоритм Евклида, для нахождения обратного мультипликативного
void evkl(BigNumber& a, BigNumber& b, BigNumber& d);
// Генерация простых чисел
string getSimple();
string getSimple(int a);
// Получить экспоненту
BigNumber getExp(const BigNumber & phi);
// Функция получения ключей
void getKeys();
//Функция перевода букв в числа
vector <string> getNums(string message);
void decryption(BigNumber d,BigNumber n, BigNumber c);
string getMessage();
void decryption();
//Записать число в файл
void writeIn(BigNumber num);
void encryption();