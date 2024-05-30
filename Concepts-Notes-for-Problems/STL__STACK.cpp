#include<iostream>
#include<stack>     // stl stack    ---> library
                    // stack is LIFO -> plates in wedding
using namespace std;

int main()
{
    // creating a stack
    stack<string> s;

    // inserting elements
    s.push("hello");
    s.push("hola");

    // checking top element
    s.top();

    // pop elements
    s.pop();

    // checking size
    s.size();

    // checking empty or not
    s.empty();

}
