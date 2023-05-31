// Operators


#include <iostream>
using namespace std;

int main()
{
    // pre-increment & post-increment operators
    int i = 1;
    i = i++ + ++i; // {i=1} (then i=2 post) + (pre, i=2+1) {i=3}
 // i = 1 + 3

    cout << i;

    return 0;
}


// MISCELLANEOUS OPERATORS :

// sizeof() -> return the size of variable
// condition?x:y -> if conditon is true then returns x ,if false then return y
// cast -> convert one data into another
// comma(,) -> causes a sequence of operations to be performed {a = (2,3,4),,,,, so the final value of a is 4,,last value}
// & -> returns the address of variable (memory allocation address)
// * -> pointer to a variable