// Continue -> This is use to skip the code whatever written after and continue the iterration till the end

#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Hi" << endl;
        cout << "Hey" << endl;
        continue;

        // here this written satatement is after the continue statement so this will going to be skipped in every iteration
        cout << "Hello" << endl;
    }
}