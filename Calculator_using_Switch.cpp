// Implement a basic calculator using switch statement

#include <iostream>
using namespace std;

int main()
{
    float n1, n2;
    cout << "Enter your Number" << endl;
    cin >> n1 >> n2;

    char oper;
    cout << "Input an Operator" << endl;
    cin >> oper;

    switch (oper)
    {
    case '+':
        cout << "Sum of two number is : " << n1 + n2 << endl;
        break;
    case '-':
        cout << "Substraction of two number is : " << n1 - n2 << endl;
        break;
    case '*':
        cout << "Multiplication of two number is : " << n1 * n2 << endl;
        break;
    case '/':
        cout << "Division of two number is : " << n1 / n2 << endl;
        break;

    default:
    cout << "Enter another operator";
        break;
    }
}