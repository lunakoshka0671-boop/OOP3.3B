
#include "CharLine.h"
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>

// Конструктор без параметрів
CharLine::CharLine() : Pair(), N(0), s(nullptr)
{
    SetS("");
}

// Конструктор з рядком
CharLine::CharLine(const char* value) : Pair(), N(0), s(nullptr)
{
    if (!SetS(value))
    {
        cerr << "Invalid string!" << endl;
        exit(1);
    }
}

// Конструктор з довжиною та рядком
CharLine::CharLine(int n, const char* value)
    : Pair(), N(0), s(nullptr)
{
    if (!SetS(value) || N != n)
    {
        cerr << "Invalid string length!" << endl;
        exit(1);
    }
}

// Конструктор копіювання
CharLine::CharLine(const CharLine& other)
    : Pair(other), N(0), s(nullptr)
{
    if (!SetS(other.s))
    {
        cerr << "Copy error!" << endl;
        exit(1);
    }
}

// Деструктор
CharLine::~CharLine()
{
    delete[] s;
}

// Гетери
int CharLine::GetN() const
{
    return N;
}

const char* CharLine::GetS() const
{
    return s;
}

// Сетер довжини
bool CharLine::SetN(int value)
{
    if (value < 0 || s == nullptr)
        return false;

    char* temp = new char[value + 1];

    int copyN = min(N, value);

    for (int i = 0; i < copyN; i++)
        temp[i] = s[i];

    for (int i = copyN; i < value; i++)
        temp[i] = ' ';

    temp[value] = '\0';

    delete[] s;
    s = temp;
    N = value;

    return true;
}

// Сетер рядка
bool CharLine::SetS(const char* value)
{
    if (value == nullptr)
        return false;

    int newN = static_cast<int>(strlen(value));

    char* temp = new char[newN + 1];
    strcpy_s(temp, newN + 1, value);

    delete[] s;
    s = temp;
    N = newN;

    return true;
}

// Отримання символу за позицією
char CharLine::GetChar(int position) const
{
    if (position < 0 || position >= N)
        return '\0';

    return s[position];
}

// Оператор індексації
char CharLine::operator[](int position) const
{
    if (position < 0 || position >= N)
        throw out_of_range("Invalid string position");

    return s[position];
}

// Перевірка наявності символу
bool CharLine::ContainsChar(char c) const
{
    return strchr(s, c) != nullptr;
}

// Перевірка наявності підрядка
bool CharLine::ContainsSubstring(const CharLine& substring) const
{
    return strstr(s, substring.s) != nullptr;
}

// Конкатенація рядків
CharLine CharLine::operator+(const CharLine& other) const
{
    string result = string(s) + string(other.s);
    return CharLine(result.c_str());
}

// Оператори порівняння
bool CharLine::operator==(const CharLine& other) const
{
    return strcmp(s, other.s) == 0;
}

bool CharLine::operator!=(const CharLine& other) const
{
    return !(*this == other);
}

bool CharLine::operator<(const CharLine& other) const
{
    return strcmp(s, other.s) < 0;
}

bool CharLine::operator>(const CharLine& other) const
{
    return other < *this;
}

bool CharLine::operator<=(const CharLine& other) const
{
    return !(*this > other);
}

bool CharLine::operator>=(const CharLine& other) const
{
    return !(*this < other);
}

// Префіксний інкремент
CharLine& CharLine::operator++()
{
    string result = string(s) + "+";
    SetS(result.c_str());
    return *this;
}

// Постфіксний інкремент
CharLine CharLine::operator++(int)
{
    CharLine temp(*this);

    string result = string(s) + "*";
    SetS(result.c_str());

    return temp;
}

// Префіксний декремент
CharLine& CharLine::operator--()
{
    if (N > 0)
    {
        string result(s);
        result.erase(N - 1, 1);
        SetS(result.c_str());
    }

    return *this;
}

// Постфіксний декремент
CharLine CharLine::operator--(int)
{
    CharLine temp(*this);

    if (N > 0)
    {
        string result(s);
        result.erase(0, 1);
        SetS(result.c_str());
    }

    return temp;
}

// Оператор присвоєння
CharLine& CharLine::operator=(const CharLine& other)
{
    if (this != &other)
    {
        SetS(other.s);
        Pair::operator=(other);
    }

    return *this;
}

// Перетворення до string
CharLine::operator string() const
{
    return string(s);
}

