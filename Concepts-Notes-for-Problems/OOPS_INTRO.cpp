/*

whenever we create object it calls constructor by default

Constructer have:
        - no return type
        - no input parameter


constructor will have both if we define otherwise,,, by default it will not have

*/

/* 

In calss we have 3 access modifiers -> private, public, protected
    private --> access only in class
    public --> access anywhere

*/

#include <iostream>
using namespace std;

// defining class
class Hero {
    // properties/ data member
    private:
    int health;

    public:
    char level;


    // we use getter and setter to access private data
    // getter -->  to get data
    int getHealth() {
        return health;
    }
    // setter -->  to set data
    void setHealth(int h) {
        health = h;
    }




    Hero() {    // this is default constructor which we have to create when we creating parameterirized constructor
        cout << "Hero Constructor" << endl;
    }

    // If we define any constructor then the default one will die(not exist)... we have to recreate it by own

    // this keyword     -> this is a pointer to current Object,,,  which stores address of object,,, also use to acess
    Hero(int health, char level) {      // parameterized
        this->health = health;
        this->level = level;
    }


    // Default COPY constructor is SHALLOW copy -> Same memory access,,, pointing the same address  ... so if you change value at one place it changes at another as well..
    
    // Defined constructor is DEEP copy -> create new memory for copy

    // creating own copy constructor
    Hero(Hero& temp) {
        int *arr = new int[20];

        this->health = temp.health;
        this->level = temp.level;
    }




    // Destructor -> Memory De-allocation / free memory
    ~Hero() {
        cout << "Destructor called" << endl;
    }
    
    // destructure called automatically for static allocation
    // for dynamically allocation we have to call destructure manually




    // Static Keyword -> create a data member which belongs to class ,,, no need to create object to access
    static int timeToComplete;      // initialize outside the class




    // static functon -> access only static member
    static int random() {
        return timeToComplete;
    }


};
    // we can define class in another file also


// SYNTAX -> datatype    ClassName     ::(scope rsolution operator)      fieldName/DataMemberName
int Hero::timeToComplete = 5;



int main()
{
    // creating an object
    Hero h1;        // static allocation

    cout << "Size: " << sizeof(h1) << endl;         // takes the same size of the defined properties,,, without defined properties it will take 1 byte memory for identification/track


    // access data using dot(.) operator
    h1.setHealth(60);
    h1.level = 'A';

    cout << "Health is: " << h1.getHealth() << endl;
    cout << "level is: " << h1.level << endl;




    Hero *h2 = new Hero;        // dynamically allocation
    // use arrow for (*_)
    h2->setHealth(40);

    cout << "Health is: " << (*h2).getHealth() << endl;
    // alternative using arrow
    cout << "Health is: " << h2->getHealth() << endl;





    // Copy Constructo
    Hero A(30, 'A');

    // copy constructor called here
    Hero R(A);  // R copy A 
    // above line is:
        // R.health = A.health
        // R.level = A.level 



    // manually destructure called for dynamically allocation
    delete h2;


    // print static member without create object
    cout << Hero::timeToComplete << endl;


    return 0;
}