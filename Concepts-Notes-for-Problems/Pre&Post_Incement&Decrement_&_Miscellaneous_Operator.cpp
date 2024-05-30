// Operators

#include <iostream>
using namespace std;

int main()
{
    // post-increment & pre-increment operators
    int i = 1;
    int j = 10;

    i = i++ + ++i; // {i=1} (then i=2 post) + (pre, i=2+1) {i=3}
 // i = 1 + 3

    cout << i;

    cout << endl;

    // post-decrement & pre-decrement operators
    j = j-- + --j; // {j=10} (then j=9 post) + (pre, j=9-1) {j=8}
 // j = 10 + 8
    cout << j;

    return 0;
}

// MISCELLANEOUS OPERATORS :

// sizeof() -> return the size of variable
// condition?x:y -> if conditon is true then returns x ,if false then return y
// cast -> convert one data into another
// comma(,) -> causes a sequence of operations to be performed {a = (2,3,4),,,,, so the final value of a is 4,,last value}
// & -> returns the address of variable (memory allocation address)
// * -> pointer to a variable