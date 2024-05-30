/*

Array is a collection of same type of data

*/

#include<iostream>
using namespace std;

int main()
{
    // declaration
    int numbers[15];

    // accessing an array
    cout << "Value at 1 index " << numbers[1];

    // cannot access this because it is not existed, throws error
    cout << "Value at 20 index " << numbers[20];

    // initializing an array
    int second[15] = {0, 7, 11};

    // accessing an element
    cout << "Value at 2 index " << second[2];

    
    // print the array
    int third[10] = {2,7};

    int n=10;
    for (int i = 0; i < n; i++)
    {
        cout << third[i] << " ";        // this will print 2 7 0 0 0 0 0 0 0 0..... other values will be zero as not declared
    }


    // initialize all locations with 0
    int fourth[5] = {0};
    int n=5;
    for (int i = 0; i < n; i++)
    {
        cout << fourth[i] << " ";        // this will print 0 0 0 0 0..... other values will be zero as not declared
    }



    // initialize all locations with 1 is not possible with below code
    int fifth[5] = {0};
    int n=5;
    for (int i = 0; i < n; i++)
    {
        cout << fifth[i] << " ";        // this will print 1 0 0 0 0 0..... other values will be zero as not declared
    }

    

}

/*

     Similarly we can define arrays of type CHAR, DOUBLE, FLOAT, BOOL

*/