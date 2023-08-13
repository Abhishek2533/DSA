#include <iostream>
using namespace std;


class Animal {
    public:
    int dob;
};

class Human {
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge() {
        return this-> age;
    }
    void setWeight(int w) {
        this->weight = w;
    }
};


// inheritance SYNTAX ->    class   className:   modifier(public/private/protected)    parentClassName  {}
class Male: public Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }
};


// Multiple Inheritance
class Child: public Human, public Animal {
    void print() {
        cout << "Multiple Inheritance";
    }
};

int main()
{
    // cretion of Object
    Male object1;

    // access parent inherited properties
    cout << object1.age << endl;
    cout << object1.weight << endl;
    cout << object1.height << endl;

    // access own properties
    cout << object1.color << endl;
    object1.sleep();

    // set value in parent inherited
    object1.setWeight(73);
    cout << object1.weight << endl;



    return 0;
}

// Note -> Private data member of any class cannot be inherited