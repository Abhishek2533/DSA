#include <iostream>
using namespace std;

void update(int *p)
{
    // by the following line we cannot update the value in main function
    p = p + 1;

    // to update value in main use the following way:
    *p = *p + 1;
}

int getSum(int arr[], int n)
{
    // here if we check the size of array which is 20,,, the output is 8 bcoz it passes pointer not the array
    cout << "Size of arr: " << sizeof(arr) << endl;
    // it means this will passes the whole array,, it will passes the address to perform operations

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int val = 5;
    int *p = &val;

    cout << "Before Function: " << *p << endl;
    update(p);
    cout << "After Function: " << *p << endl;

    int arr[5] = {1,2,3,4,5};

    cout << "Sum is: " << getSum(arr, 5)<< endl;
    return 0;
}