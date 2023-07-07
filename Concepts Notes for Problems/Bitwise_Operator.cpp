#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 6;

    // & (and) -> both must be 1 then 1 otherwise 0
    cout << " a and b " << (a & b) << endl;

    // | (or) -> anyone must be 1 then 1 otherwise 0
    cout << " a or b " << (a | b) << endl;

    // ~ (not) -> it converts the value to opposite
    cout << " not a " << ~a << endl;
    cout << " not b " << ~b << endl;

    // ^ (xor) -> if both are same then 0 otherwise 1
    cout << " a xor b " << (a ^ b) << endl;

    // << (right shift)
    cout << (17 >> 1) << endl;
    cout << (17 >> 2) << endl;

    // >> (left shift)
    cout << (19 << 1) << endl;
    cout << (17 << 2) << endl;
}



/*
Left shift (<<) -> in smaller nubers we can say that number will multiply by 2 in each shift, but it will not works everytime such as for large numbers it will become negative...

Right shift (>>) -> here we can say that number will divide by 2 in each shift
*/

/*
In positive numbers PADDING is given with 0, but in negative numbers PADDING is ' Compiler Dependent '
*/