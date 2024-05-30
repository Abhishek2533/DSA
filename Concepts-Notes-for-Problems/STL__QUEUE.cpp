#include<iostream>
#include<queue>     // stl queue    ---> library
                    // queue is FIFO ->  line
using namespace std;

int main()
{
    // creating a queue
    queue<string> q;

    // inserting elements
    q.push("hello");
    q.push("hola");

    // checking first element
    q.front();

    // pop elements
    q.pop();

    // checking size
    q.size();

    // checking empty or not
    q.empty();

}
