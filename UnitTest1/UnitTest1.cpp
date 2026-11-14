
#include "pch.h"
#include "CppUnitTest.h"

#include "../OOP3.3B/Pair.cpp"
#include "../OOP3.3B/CharLine.cpp"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOP33BTests
{
    TEST_CLASS(PairTests)
    {
    public:

        TEST_METHOD(TestPairConstructors)
        {
            Pair p1;
            Assert::AreEqual(0, p1.GetFirst());
            Assert::AreEqual(0, p1.GetSecond());

            Pair p2(5, 10);
            Assert::AreEqual(5, p2.GetFirst());
            Assert::AreEqual(10, p2.GetSecond());

            Pair p3(p2);
            Assert::AreEqual(5, p3.GetFirst());
            Assert::AreEqual(10, p3.GetSecond());
        }

        TEST_METHOD(TestPairSetters)
        {
            Pair p;

            Assert::IsTrue(p.SetFirst(7));
            Assert::IsTrue(p.SetSecond(12));

            Assert::AreEqual(7, p.GetFirst());
            Assert::AreEqual(12, p.GetSecond());
        }

        TEST_METHOD(TestPairComparisons)
        {
            Pair p1(2, 5);
            Pair p2(2, 5);
            Pair p3(3, 1);

            Assert::IsTrue(p1 == p2);
            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 < p3);
            Assert::IsTrue(p3 > p1);
            Assert::IsTrue(p1 <= p2);
            Assert::IsTrue(p3 >= p1);
        }
    };

    TEST_CLASS(CharLineTests)
    {
    public:

        TEST_METHOD(TestConstructors)
        {
            CharLine a;
            Assert::AreEqual(0, a.GetN());
            Assert::AreEqual(std::string(""), std::string(a.GetS()));

            CharLine b("Hello");
            Assert::AreEqual(5, b.GetN());
            Assert::AreEqual(std::string("Hello"), std::string(b.GetS()));

            CharLine c(5, "World");
            Assert::AreEqual(5, c.GetN());
            Assert::AreEqual(std::string("World"), std::string(c.GetS()));

            CharLine d(b);
            Assert::AreEqual(std::string("Hello"), std::string(d.GetS()));
        }

        TEST_METHOD(TestSetters)
        {
            CharLine a("Hello");

            Assert::IsTrue(a.SetS("World"));
            Assert::AreEqual(5, a.GetN());
            Assert::AreEqual(std::string("World"), std::string(a.GetS()));

            Assert::IsTrue(a.SetN(3));
            Assert::AreEqual(3, a.GetN());
            Assert::AreEqual(std::string("Wor"), std::string(a.GetS()));
        }

        TEST_METHOD(TestGetCharAndIndex)
        {
            CharLine a("Hello");

            Assert::AreEqual('H', a.GetChar(0));
            Assert::AreEqual('e', a[1]);
            Assert::AreEqual('o', a[4]);
        }

        TEST_METHOD(TestContainsChar)
        {
            CharLine a("Hello");

            Assert::IsTrue(a.ContainsChar('e'));
            Assert::IsTrue(a.ContainsChar('H'));
            Assert::IsFalse(a.ContainsChar('z'));
        }

        TEST_METHOD(TestContainsSubstring)
        {
            CharLine a("Hello World");
            CharLine b("World");
            CharLine c("Test");

            Assert::IsTrue(a.ContainsSubstring(b));
            Assert::IsFalse(a.ContainsSubstring(c));
        }

        TEST_METHOD(TestConcatenation)
        {
            CharLine a("Hello");
            CharLine b(" World");

            CharLine c = a + b;

            Assert::AreEqual(
                std::string("Hello World"),
                std::string(c.GetS())
            );
        }

        TEST_METHOD(TestComparisons)
        {
            CharLine a("Apple");
            CharLine b("Apple");
            CharLine c("Banana");

            Assert::IsTrue(a == b);
            Assert::IsFalse(a != b);
            Assert::IsTrue(a < c);
            Assert::IsTrue(c > a);
            Assert::IsTrue(a <= b);
            Assert::IsTrue(c >= a);
        }

        TEST_METHOD(TestAssignment)
        {
            CharLine a("First");
            CharLine b;

            b = a;

            Assert::AreEqual(
                std::string("First"),
                std::string(b.GetS())
            );
        }

        TEST_METHOD(TestIncrement)
        {
            CharLine a("Text");

            ++a;
            Assert::AreEqual(std::string("Text+"), std::string(a.GetS()));

            CharLine b("Text");
            CharLine old = b++;

            Assert::AreEqual(std::string("Text"), std::string(old.GetS()));
            Assert::AreEqual(std::string("Text*"), std::string(b.GetS()));
        }

        TEST_METHOD(TestDecrement)
        {
            CharLine a("Text");

            --a;
            Assert::AreEqual(std::string("Tex"), std::string(a.GetS()));

            CharLine b("Text");
            CharLine old = b--;

            Assert::AreEqual(std::string("Text"), std::string(old.GetS()));
            Assert::AreEqual(std::string("ext"), std::string(b.GetS()));
        }

        TEST_METHOD(TestStringConversion)
        {
            CharLine a("Hello");

            std::string result = a;

            Assert::AreEqual(std::string("Hello"), result);
        }
    };
}

