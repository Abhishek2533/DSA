// To print all the prime numbers between two numbers

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    for (int num = a; num <= b; num++)
    {
        int i;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)       // % -> this is module operator which gives remainder
            {
                break;
            }
        }
        if (i == num)
        {
            cout << num << endl;
        }
    }

    return 0;
}