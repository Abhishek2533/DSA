#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {12, 24, 45, 46};

    // ways to print address of first memory block
    cout << arr << endl;
    cout << &arr << endl;
    cout << &arr[0] << endl;


    // ways to print values of any index
    cout << *arr << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << *(arr) + 1 << endl;
    cout << *(arr + 2) << endl;

    int i = 3;
    cout << i[arr] << endl;     // this will excecute as: *(i + arr) ,, so this not throw error
}