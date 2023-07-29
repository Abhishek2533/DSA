#include <iostream>
#include <deque> // stl deque   ---> library
                 // Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.
using namespace std;

int main()
{
    // creating a deque
    deque<int> d;

    // inserting from front
    d.push_front(1);

    // inserting from back
    d.pop_back();

    // pop from front
    d.pop_front();

    // pop from back
    d.pop_back();

    // print 1st index array
    d.at(1);        // SYNTAX -> deque.at(index)

    // checking empty or not
    d.empty();

    // delete deque
    d.erase(d.begin(), d.begin() + 1);      // we have to define what we wnat to delete,,, i.e., wnat to delete single element or a specific range...
                                            // SYNTAX -> d.erease(start, end)

    // checking size
    d.size();
}