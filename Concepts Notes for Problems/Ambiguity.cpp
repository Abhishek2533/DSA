#include <iostream>
using namespace std;


class A {
    public:

    void func() {
        cout << "this is A" << endl;
    }
};


class B {
    public:

    void func() {
        cout << "this is B" << endl;
    }
};


class C: public A, public B {

};

int main()
{
    C obj;

    // Uisng ambiguity by scope resolver -> ::
    obj.A::func();
    obj.B::func();

    return 0;
}