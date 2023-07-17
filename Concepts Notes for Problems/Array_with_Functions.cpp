#include <iostream>
using namespace std;

//  function declaration for array :
    // printArray(int arr[], int size)
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int third[10] = {2, 7};
    printArray(third, 10);
}