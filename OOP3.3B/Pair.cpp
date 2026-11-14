
#include "Pair.h"

// Конструктор без параметрів
Pair::Pair()
{
    first = 0;
    second = 0;
}

// Конструктор ініціалізації
Pair::Pair(int first, int second)
{
    if (!SetFirst(first) || !SetSecond(second))
    {
        cerr << "Invalid Pair values!" << endl;
        exit(1);
    }
}

// Конструктор копіювання
Pair::Pair(const Pair& other)
{
    SetFirst(other.first);
    SetSecond(other.second);
}

// Гетери
int Pair::GetFirst() const
{
    return first;
}

int Pair::GetSecond() const
{
    return second;
}

// Сетер першого числа
bool Pair::SetFirst(int value)
{
    first = value;
    return true;
}

// Сетер другого числа
bool Pair::SetSecond(int value)
{
    second = value;
    return true;
}

// Операція рівності
bool Pair::operator==(const Pair& other) const
{
    return first == other.first && second == other.second;
}

// Операція нерівності
bool Pair::operator!=(const Pair& other) const
{
    return !(*this == other);
}

// Операція менше
bool Pair::operator<(const Pair& other) const
{
    if (first < other.first)
        return true;

    if (first == other.first && second < other.second)
        return true;

    return false;
}

// Операція більше
bool Pair::operator>(const Pair& other) const
{
    return other < *this;
}

// Операція менше або дорівнює
bool Pair::operator<=(const Pair& other) const
{
    return !(*this > other);
}

// Операція більше або дорівнює
bool Pair::operator>=(const Pair& other) const
{
    return !(*this < other);
}

// Оператор виведення
ostream& operator<<(ostream& out, const Pair& p)
{
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

// Оператор введення
istream& operator>>(istream& in, Pair& p)
{
    int first, second;

    cout << "Enter first number: ";
    in >> first;

    cout << "Enter second number: ";
    in >> second;

    if (in)
    {
        p.SetFirst(first);
        p.SetSecond(second);
    }

    return in;
}

