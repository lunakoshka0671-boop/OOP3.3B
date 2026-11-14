
#include <iostream>
#include <string>
#include "Pair.h"
#include "CharLine.h"

using namespace std;

int main()
{
    cout << "===== PAIR =====" << endl;

    Pair p1(5, 10);
    Pair p2(5, 15);

    cout << "First pair: " << p1 << endl;
    cout << "Second pair: " << p2 << endl;

    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout << "p1 < p2: " << (p1 < p2) << endl;
    cout << "p1 > p2: " << (p1 > p2) << endl;
    cout << "p1 <= p2: " << (p1 <= p2) << endl;
    cout << "p1 >= p2: " << (p1 >= p2) << endl;

    Pair p3 = p1;
    cout << "Copy of p1: " << p3 << endl;

    cout << "\n===== CHARLINE =====" << endl;

    CharLine a("Hello");
    CharLine b("World");

    cout << "First string: " << a.GetS() << endl;
    cout << "Second string: " << b.GetS() << endl;

    cout << "Length: " << a.GetN() << endl;

    cout << "Character at position 1: " << a.GetChar(1) << endl;
    cout << "Using operator []: " << a[0] << endl;

    cout << "Contains 'e': "
        << (a.ContainsChar('e') ? "Yes" : "No") << endl;

    CharLine sub("ell");

    cout << "Contains substring 'ell': "
        << (a.ContainsSubstring(sub) ? "Yes" : "No") << endl;

    CharLine sum = a + b;
    cout << "Concatenation: " << sum.GetS() << endl;

    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    cout << "\nPrefix ++: " << (++a).GetS() << endl;

    cout << "Postfix ++: " << (a++).GetS() << endl;
    cout << "After postfix ++: " << a.GetS() << endl;

    cout << "Prefix --: " << (--a).GetS() << endl;

    cout << "Postfix --: " << (a--).GetS() << endl;
    cout << "After postfix --: " << a.GetS() << endl;

    string text = a;
    cout << "Conversion to string: " << text << endl;

    cout << "\n===== ARRAY OF OBJECTS =====" << endl;

    CharLine arr[3] = {
        CharLine("Apple"),
        CharLine("Banana"),
        CharLine("Orange")
    };

    for (int i = 0; i < 3; i++)
        cout << arr[i].GetS() << endl;

    cout << "\n===== OBJECT INPUT =====" << endl;

    CharLine input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "You entered: " << input.GetS() << endl;

    cout << "\n===== CLASS SIZE =====" << endl;

    cout << "Size of Pair: " << sizeof(Pair) << endl;
    cout << "Size of CharLine: " << sizeof(CharLine) << endl;

    return 0;
}
