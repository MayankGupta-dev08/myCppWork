// Print whether all prime numbers between a range of two numbers given by users.

#include <iostream>
using namespace std;

int main()
{
    int a, b, flag;
    cout << "Enter lower value of range: ";
    cin >> a;
    cout << "Enter lower value of range: ";
    cin >> b;
    cout << "All prime numbers from " << a << " to " << b << " are:\n";

    for (int num = a; num <= b; num++)
    {
        if (num < 2)
            {
                continue;
            }
        flag = 0;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                flag += 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << num << " ";
        }
    }

    cout << endl;
    return 0;
}