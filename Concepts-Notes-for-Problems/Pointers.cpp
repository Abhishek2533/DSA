#include<iostream>
using namespace std;

int main()
{
    int num = 5;

    cout << num << endl;

    // address operator -> &
    cout << "Address of num is: " << &num << endl;

    // creating a pointer
    int *ptr= &num;

    // to access address of pointer
    cout << "Address in ptr: " << ptr << endl;

    // to print value at address that stored by pointer
    cout << "Value in ptr: " << *ptr << endl;

    // creating double size pointer
    double d = 4.5;
    double *p = &d;

    cout << "Address in ptr: " << p << endl;
    cout << "Value in ptr: " << *p << endl;

    // size of integer
    cout << "Size of integer is: " << sizeof(num) << endl;

    // checking the size of all pointers
    cout << "Size of pointer is: " << sizeof(ptr) << endl;
    cout << "Size of pointer is: " << sizeof(p) << endl;
                // here we observe that pointers size ia always 8,,, as it stores address only,,, so int, double, char, float.... all are of 8 byte

    // incrementing the value using pointers
    int val  = 5;
    int *p1 = &val;

    cout << "Before increment: " << val;

    (*p1)++; 
    cout << "After increment: " << val;


    // copying a pointer
    int *q = p1;

    cout << "Copied address: " << q << endl;
    cout << "Copied value: " << *q << endl;


    // what if we increment pointer instead of value:
    int i = 5;
    int *t = &i;

    cout << "Before increment of pointer: " << t << endl;
    t = t+1;
    cout << "After increment of pointer: " << t << endl;
    // we have observed that it will move on to next memory block (+4 bytes) ,,, e.g., t = 100 then, t+1 = 104

    return 0;
}