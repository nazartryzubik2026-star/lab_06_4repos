#include "pch.h"
#define UNIT_TESTING
#include "CppUnitTest.h"
#include "../Lab_6_4/Source.cpp" // Перевірте назву папки (Lab_6_4 або Lab6_4)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
    TEST_CLASS(UnitTest64)
    {
    public:
        // Перевірка кількості від’ємних елементів
        TEST_METHOD(TestCountNegative)
        {
            double a[4] = { 1.5, -2.0, 0.0, -3.5 };
            Assert::AreEqual(2, CountNegative(a, 4, 0));
        }

        // Перевірка пошуку індексу мінімального за модулем елемента
        TEST_METHOD(TestIMinAbs)
        {
            double a[5] = { 5.0, -1.0, 3.0, 0.5, -4.0 };
            int imin = 0;
            IMinAbs(a, 5, 1, imin);
            Assert::AreEqual(3, imin); // 0.5 знаходиться за індексом 3
        }

        // Перевірка суми модулів після мінімального елемента за модулем
        TEST_METHOD(TestSumAbs)
        {
            double a[5] = { 5.0, -1.0, 3.0, 0.5, -4.0 };
            // За індексом 3 знаходиться 0.5, елементи після нього: |-4.0| = 4.0
            Assert::AreEqual(4.0, SumAbs(a, 5, 4), 1e-9);
        }

        // Перевірка сортування та піднесення до квадрата від’ємних елементів
        TEST_METHOD(TestSortAndSquareNegative)
        {
            double a[5] = { -3.0, 5.0, -1.0, 2.0, -2.0 };
            SortNegative(a, 5, 0);
            SquareNegative(a, 5, 0);

            // Очікуваний результат: від’ємні {-3, -1, -2} перетворюються на {1.0, 4.0, 9.0}
            Assert::AreEqual(1.0, a[0], 1e-9);
            Assert::AreEqual(5.0, a[1], 1e-9);
            Assert::AreEqual(4.0, a[2], 1e-9);
            Assert::AreEqual(2.0, a[3], 1e-9);
            Assert::AreEqual(9.0, a[4], 1e-9);
        }
    };
}