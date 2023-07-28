#include <iostream>
#include <array> // STL array   ----> library

using namespace std;

int main()
{
    int basic[3] = {1, 2, 3};

    // following array is created from the basic array using stl array
    array<int, 4> a = {1, 2, 3, 4};

    int size = a.size();

    for (int i = 0; i < size; i++)
    {
        // printing all elements
        cout << a[i] << endl;
    }

    // printing 2nd element in array using  "array.at(index)" method
    cout << "Element at 2nd Index -> " << a.at(2) << endl;

    // checking the array is empty or not,,, boolean output is 0 or 1
    cout << "Empty or Not -> " << a.empty() << endl;

    // starting element of array
    cout << "First Element -> " << a.front() << endl;

    // last element of array
    cout << "Last Element -> " << a.back() << endl;
}