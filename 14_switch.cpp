// To write a program for understanding switch statement. if break is not used in any of them then its below case will also be executed irrespective of its condition.

#include <iostream>
using namespace std;

int main(){

    char a;
    cout<<"Enter any option from a,b,c,d,e,f or g: ";
    cin>>a;
    
    switch(a)
    {
        case 'a':
            cout<<"Hindi: Namaste"<<endl;
            break;
        case 'b':
            cout<<"English: Hello"<<endl;
            break;
        case 'c':
            cout<<"French: Bonjour"<<endl;
            break;
        case 'd':
            cout<<"Spanish: Hola"<<endl;
            break;
        case 'e':
            cout<<"Italian: Salve"<<endl;
            break;
        case 'f':
            cout<<"Japaneese: Konnichiwa"<<endl;
            break;
        case 'g':
            cout<<"German: Guten Tag"<<endl;
            break;
        default:
            cout<<"I am still learning more!!\n";
            break;
    }    
    
    return 0;
}