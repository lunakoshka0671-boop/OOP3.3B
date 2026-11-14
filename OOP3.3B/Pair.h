
#pragma once
#include <iostream>
using namespace std;

class Pair
{
private:
    int first;
    int second;

public:
    // Конструктори
    Pair();
    Pair(int first, int second);
    Pair(const Pair& other);

    // Гетери
    int GetFirst() const;
    int GetSecond() const;

    // Сетери
    bool SetFirst(int value);
    bool SetSecond(int value);

    // Операції порівняння
    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;
    bool operator<(const Pair& other) const;
    bool operator>(const Pair& other) const;
    bool operator<=(const Pair& other) const;
    bool operator>=(const Pair& other) const;

    // Оператори введення та виведення
    friend ostream& operator<<(ostream& out, const Pair& p);
    friend istream& operator>>(istream& in, Pair& p);
};


