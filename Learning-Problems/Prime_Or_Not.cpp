// Write a program to check the given number is prime or not

#include <iostream>
using namespace std;

int main()
{
    int n, i = 2;
    cout << "Enter any positive integer: "; // Taking input from user
    cin >> n;

    if (i < n)
    {
        if (n % i == 0)
        {
            cout << "This number is not a PRIME";
        }
        else
        {
            cout << "This number is a PRIME";
        }
        i = i + 1;
    }
}