#include <iostream>
using namespace std;

void update(int **ptr2)
{
    // by the following line we cannot update the value in main function
    ptr2 = ptr2 + 1;

    // by the following line we update the value of ptr1 which is unnecessary
    *ptr2 = *ptr2 + 1;

    // to update value in main use the following way:
    *ptr2 = *ptr2 + 1;
}

int main()
{
    int i = 5;
    int *ptr1 = &i;     // single pointer contains address of i
    int **ptr2 = &ptr1; // double pointer contains address of ptr1



    // ways to print the value of i:
    cout << i << endl;
    cout << *ptr1 << endl;
    cout << **ptr2 << endl;



    // ways to print the address of i:
    cout << &i << endl;
    cout << ptr1 << endl;
    cout << *ptr2 << endl;


    // updating value using double pointer
    cout << "Before Function value of i: " << i << endl;
    cout << "Before Function value of ptr1: " << ptr1 << endl;
    cout << "Before Function value of ptr2: " << ptr2 << endl;
    update(ptr2);
    cout << "After Function value of i: " << i << endl;
    cout << "After Function value of ptr1: " << ptr1 << endl;
    cout << "After Function value of ptr2: " << ptr2 << endl;

    return 0;
}