#include<iostream>
using namespace std;

void dummy(int n)
{
    n++;    //n=6
    cout << "n is " << n << endl;    // n=6
}

int main()
{
    int n;      // n =5
    cin >> n;

    dummy(n);   // return n=6

    cout << "Number is " << n;  // here the value of n is 5 not 6 because both n are different only name is same,,, this is called pass by value
    
    // here another n is copied in dummy from main not the n given to dummy
    // if the n is given then it will called pass by reference
}