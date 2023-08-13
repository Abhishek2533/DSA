// This is Compile-time polymorphism  /  static polymorphism

#include <iostream>
using namespace std;


class B {
    public:
    int a;
    int b;

    int add() {
        return a+b;
    }



    // operator overload

    // SYNTAX -> returnType     operator _        input
    void operator+ (B &obj) {
        int val1 = this->a;
        int val2 = obj.a;
        cout << "Output: " << val2 - val1 << endl;
    }
};


int main()
{   
    B obj1, obj2;
    obj1.a = 1;
    obj2.a = 2;

    // first argument is (this), then operator, then input argument
    obj1 + obj2;

    return 0;
}


// Operator which cannot be overload --> 