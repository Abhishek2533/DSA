// Write a program to print the sum of n numbers

#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;
    cout << "Enter the number: ";
    cin >> num;

    int i = 1;

    while (i <= num)
    {
        sum = sum + i;
        i = i + 1;
    }

    cout << "Sum of numbers is:" << sum;
}
