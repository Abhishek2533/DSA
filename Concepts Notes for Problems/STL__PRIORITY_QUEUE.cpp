#include<iostream>
#include<queue>     // stl queue    ---> library
                    // queue of which 1st element is always greatest
using namespace std;

int main()
{
    // creating a max heap
    priority_queue<int> maxi;

    // creating a min heap
    priority_queue<int,vector<int>, greater<int> > mini;

    // inserting elements
    maxi.push(1);
    mini.push(2);

    // checking first element
    maxi.top();
    mini.top();

    // pop elements
    maxi.pop();
    mini.pop();

    // checking size
    maxi.size();
    mini.size();

    // checking empty or not
    maxi.empty();
    mini.empty();

}
