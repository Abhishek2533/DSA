// This is Run-time polymorphism  /  dynamic polymorphism
// Overriding   -> depends on inheritance

#include <iostream>
using namespace std;


class Animal {
    public:
    void speak() {
        cout << "speak Animal" << endl;
    }
};


class Dog: public Animal {
    public:

    // This will override the function because of our implementation
    void speak() {
        cout << "speak Dog" << endl;
    }
};

int main()
{
    Dog obj;
    obj.speak();

    return 0;
}