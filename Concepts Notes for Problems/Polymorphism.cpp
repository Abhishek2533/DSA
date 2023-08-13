// Poly - many, morph - form
// -> exist in many forms

#include <iostream>
using namespace std;


class A {

    public:
    void sayHello() {
        cout << "Hello" << endl;
    }

    void sayHello(string name) {
        cout << "Hello" << name << endl;
    }

    int sayHello(int age) {
        return age;
    }
};

int main()
{   
    A obj1;
    obj1.sayHello();


    return 0;
}

// Types --> Compile time polymorphism -> Operator Overload
//           Run time polymorphism -> Overriding