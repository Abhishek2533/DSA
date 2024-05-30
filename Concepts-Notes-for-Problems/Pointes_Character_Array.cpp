#include <iostream>
using namespace std;

int main()
{
    // creating array
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";

    // output of arrays
    cout << arr << endl;        // this will give ' ADDRESS ' of int array
    cout << ch << endl;         // this will give all ' VALUES ' of ch array
        // in character array pointer prints the value not addrerss as they are differently implemented
        
    return 0;
}