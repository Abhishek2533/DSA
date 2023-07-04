// Write a program to find sum of all EVEN numbers upto n

#include <iostream>
using namespace std;

int main()
{
    int num, sum = 0;

    cout << "Enter the Number:";
    cin >> num;

    int i = 1;
    while (i <= num)
    {
        if (i % 2 == 0)
        {
            // if number is even
            sum += i; // add it in sum variable.
        }
        i = i + 1; // incrementing loop counter
    }              // incrementing loop counter by one for next iteration
    cout << "Sum Of All Even Numbers Upto " << num << " Is: " << sum;
}