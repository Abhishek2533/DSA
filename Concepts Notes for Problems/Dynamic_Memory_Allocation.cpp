// Static Memory have small size in comparison to Dynamic Memory,, 
// so in runtime creating an array of user input n will cause program crash due to size
// thats why we can use Heap Memmory rather than stack for runtime memory allocaton


#include <iostream>
using namespace std;


int getSum(int *arr1, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i];
    }
    return sum;
}

int main()
{
    // stack memory allocated during compiler
    int arr[20] = {0};

    // heap memory allocate using keyword -> new
    int* ptr = new int;     // ptr store address of heap memory in stack memory 


    // taking input for size of array
    int n;
    cin >> n;

    // creating a array of size n
    int* arr1 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int ans = getSum(arr1, n);
    cout << "Sum is: " << ans;


    // to clean the storage of heap we have to delete in the following way:
    delete []arr;

    return 0;
}