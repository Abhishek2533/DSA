#include<iostream>
#include<set>   // stl set ---> library
                // set contains unique values and we camnnot modify them,,, only new values insert and delete
                // set is ordered

using namespace std;

int main()
{
    set<int> s;

    // inserting an element
    s.insert(4);

    // erase
    s.erase(0); // erase(index)

    // checking element present or not
    s.count(4);     // count(value)

    // find function
    s.find(4);      // find -> return itterator of a particular element

    // empty or not
    s.empty();

}