/*

LOCAL and GLOBAL scopes in functions
    -->
        in shorts we can create var in a block and use anywhere inside the block but we cannot use var outside the block in which it was not created and we cannot create same variable in same block

*/

#include <iostream>
using namespace std;

int main()
{
    // these are in main function so they are global function
    int a = 10;
    int b = 20;

    if (true)
    {
        // these are inside the function which is inside the main function so these are local as they created only for this function not for main(global) function
        int c = 30;
        int d = 40;

        cout << a << " " << b << " " << c << " " << d << endl;
    }

    int c = 50;
    int d = 60;

    // here it throws error of (c & d) are not define so we defined here with different values to the upper ones
    // we found that it prints the new values (50 & 60) not (30 & 40) because they were local and the scope is only for that function not outside,,, here new scope is created for these for the main function
    // Also we cannot create same variable again in same scope with same name
    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}