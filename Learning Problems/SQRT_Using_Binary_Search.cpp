#include <iostream>
using namespace std;

long long sqrt(int n)
{
    int s = 0, e = n;
    long long mid = s + (e - s) / 2;
    long long ans = -1;

    while (s <= e)
    {
        long long square = mid * mid;

        if (square == n)
        {
            return mid;
        }

        else if (square > n)
        {
            e = mid - 1;
        }

        else if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol)
{
    double factor = 1;
    double ans = tempSol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int tempSol = sqrt(n);

    cout << "Square root of " << n << " is " << morePrecision(n, 3, tempSol);
}