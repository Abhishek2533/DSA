/*

Encapsulation is use for Information Hiding / Data hiding
Encapsulation -> wrapping up data member and function
    Application -> Data hide -> security
                   Read only
                   Code Rewability
                   Unit Testing


Fully encapsulated class -> when all data members are private

*/

#include <iostream>
using namespace std;

// impletation of encapsulation
class Student {
    private:
    string name;
    int age;
    int height;

    public:
    int getAge() {
        return this->age;
    }
};

int main()
{

    Student first;

    return 0;
}