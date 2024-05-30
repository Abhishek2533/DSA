// Write a program to convert fahrenheit to celsius

#include <iostream>
using namespace std;

int main()
{
    int F, C;
    cout << "Enter the Fahrenheit Value:";
    cin >> F;

    C = ((F - 32) * 5) / 9;

    cout << "Celcius:" << C;
}