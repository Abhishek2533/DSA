#include <iostream>
#include <list> // stl list  ---> library

using namespace std;

int main()
{
    // creating a list
    list<int> l;

    // initializing with values
    list<int> n(5, 100); // STNTAX -> name(no. of elements, value for all elements)
                         // n list is created with 5 elemnts with 100 value for each -> 100,100,100,100,100

    // copy a list
    list<int> c(l);

    // inserting element from front and back respectively
    l.push_front(1);
    l.push_back(2);

    // pop element from front and back respectively
    l.pop_front();
    l.pop_back();

    // deleting an element
    l.erase(l.begin());
}