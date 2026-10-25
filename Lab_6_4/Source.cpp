#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(double* a, const int size, const double Low, const double High, int i)
{
    a[i] = Low + (High - Low) * rand() / RAND_MAX;
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(double* a, const int size, int i)
{
    cout << fixed << setprecision(2) << setw(8) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// 1.1. Кількість від’ємних елементів
int CountNegative(double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
            return 1 + CountNegative(a, size, i + 1);
        else
            return CountNegative(a, size, i + 1);
    }
    else
        return 0;
}

// 1.2. Пошук індексу мінімального за модулем елемента
void IMinAbs(double* a, const int size, int i, int& imin)
{
    if (i < size)
    {
        if (fabs(a[i]) < fabs(a[imin]))
            imin = i;
        IMinAbs(a, size, i + 1, imin);
    }
}

// Обчислення суми модулів елементів після заданого індексу
double SumAbs(double* a, const int size, int i)
{
    if (i < size)
        return fabs(a[i]) + SumAbs(a, size, i + 1);
    else
        return 0;
}

// 2. Сортування від’ємних елементів за спаданням
void MaxNegative(double* a, const int size, int j, double& max, int& imax)
{
    if (j < size)
    {
        if (a[j] < 0 && a[j] > max)
        {
            max = a[j];
            imax = j;
        }
        MaxNegative(a, size, j + 1, max, imax);
    }
}

void SortNegative(double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0)
        {
            double max = a[i];
            int imax = i;
            MaxNegative(a, size, i + 1, max, imax);
            a[imax] = a[i];
            a[i] = max;
        }
        SortNegative(a, size, i + 1);
    }
}

// Піднесення від’ємних елементів до квадрата
void SquareNegative(double* a, const int size, int i)
{
    if (i >= size) return;
    if (a[i] < 0)
        a[i] = a[i] * a[i];
    if (i < size - 1)
        SquareNegative(a, size, i + 1);
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    if (n <= 0) return 0;

    double* a = new double[n];

    Create(a, n, -10.0, 10.0, 0);
    Print(a, n, 0);

    cout << "Negative count = " << CountNegative(a, n, 0) << endl;

    int imin = 0;
    IMinAbs(a, n, 1, imin);
    cout << "Sum abs after min abs = "
        << SumAbs(a, n, imin + 1) << endl;

    SortNegative(a, n, 0);
    SquareNegative(a, n, 0);
    Print(a, n, 0);

    delete[] a;

    return 0;
}
#endif