// To write a program for a basic calculator using switch.

#include <iostream>
using namespace std;

int main()
{

    float a, b;
    char op;

    cout << "Enter number1: ";
    cin >> a;
    cout << "Enter number2: ";
    cin >> b;
    cout << "Enter any operator for performing on the two numbers: ";
    cin >> op;

    switch (op)
    {
    case '+':
        cout << a + b << endl;
        break;
    case '-':
        cout << a - b << endl;
        break;
    case '/':
        cout << a / b << endl;
        break;
    case '*':
        cout << a * b << endl;
        break;

    default:
        cout << "Something weent wrong!!\n";
        break;
    }

    return 0;
}