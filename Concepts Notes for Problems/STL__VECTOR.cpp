#include <iostream>
#include <vector> // stl vector   ----> library

using namespace std;

int main()
{
    vector<int> v; // when the vector is created ,,, initially its CAPACITY is 0

    // initialize vector with size and all elements with a value  -->
    // vector<int> a(size, value)
    vector<int> a(5, 1);

    // Copying a vector
    vector<int> b(a);

    v.capacity();
    // capacity = space assign for the elements to be inserted ,,,
    // if the capacity is full and we try to insert another element in it ,,,
    // it will create an another vector of the double capacity of that vector and then copy all elements in it and destroy the previous vector,,,
    // then it will inserts the new elemnts.

    v.push_back(1); // insert the elements in vector

    v.size(); // size = elements stored in vector

    v.pop_back(); // removing the last element

    v.clear(); // size will be 0 but the capacity will not zero,,, it remains same
}