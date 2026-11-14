
#pragma once
#include "Pair.h"
#include <string>
using namespace std;

class CharLine : public Pair
{
private:
    int N;
    char* s;

public:
    // Конструктори
    CharLine();
    explicit CharLine(const char* value);
    CharLine(int n, const char* value);
    CharLine(const CharLine& other);

    // Деструктор
    ~CharLine();

    // Гетери
    int GetN() const;
    const char* GetS() const;

    // Сетери
    bool SetN(int value);
    bool SetS(const char* value);

    // Операції роботи з рядком
    char GetChar(int position) const;
    char operator[](int position) const;

    bool ContainsChar(char c) const;
    bool ContainsSubstring(const CharLine& substring) const;

    CharLine operator+(const CharLine& other) const;

    bool operator==(const CharLine& other) const;
    bool operator!=(const CharLine& other) const;
    bool operator<(const CharLine& other) const;
    bool operator>(const CharLine& other) const;
    bool operator<=(const CharLine& other) const;
    bool operator>=(const CharLine& other) const;

    // Інкремент і декремент
    CharLine& operator++();
    CharLine operator++(int);
    CharLine& operator--();
    CharLine operator--(int);

    // Присвоєння
    CharLine& operator=(const CharLine& other);

    // Перетворення до string
    operator string() const;
};


