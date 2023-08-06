#include <iostream>
using namespace std;

// pass by value
void update1(int n)
{
    n++;
}

// pass by reference 
void update2(int& n)    // in this way we can update value in main function
{
    n++;
}

int main()
{
    int i = 5;

    //create a reference variable
    int& j = i;     // this have same memory ,,, it means i & j pointing the same location(one value with two name)

    cout << i << endl;
    i++;
    cout << i << endl;
    j++;
    cout << j << endl;
            // we can access by i & j both



    int n = 5;
    cout<< "Before function: " << n << endl;
    update1(n);
    cout<< "After update 1 - pass by value: " << n << endl;
    update2(n);
    cout<< "After update 2 - pass by reference: " << n << endl;

    return 0;
}