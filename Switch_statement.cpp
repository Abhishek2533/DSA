
// Multiple languages robot

#include<iostream>
using namespace std;

int main()
{
    char button ;
    cout << "Input a character:";
    cin >> button;

    // if (button == 'a')
    // {
    //     cout << "Hello" << endl;
    // }
    // else if (button == 'b')
    // {
    //     cout << "Nameste" << endl;
    // }
    // else if (button == 'c')
    // {
    //     cout << "Salute" << endl;
    // }
    // else if (button == 'd')
    // {
    //     cout << "Hola" << endl;
    // }
    // else if (button == 'e')
    // {
    //     cout << "Ciao" << endl;
    // }
    // else 
    // {
    //     cout << "I am still learning" << endl;
    // }

    switch (button)                     // Switch statement are the substitute for if else statement
    {
    case 'a':
        cout << "Hello" << endl;
        break;                         // break is used so that we can exit the loop and not execute the next other cases (b,c,d... after executing a)
    case 'b':
        cout << "Nameste" << endl;
        break;
    case 'c':
        cout << "Salute" << endl;
        break;
    case 'd':
        cout << "Hola" << endl;
        break;
    case 'e':
        cout << "Ciao" << endl;
        break;
    
    default: cout << "I am still learning" << endl;
        break;
    }


    return 0;
}