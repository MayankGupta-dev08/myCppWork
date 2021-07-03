/*
Create 2 classes:
    1. SimpleCalculator - Takes input of 2 numbers using a utility function and perfoms +, -, *, / and displays the results using another function.
    2. ScientificCalculator - Takes input of 2 numbers using a utility function and perfoms any four scientific operation of your chioice and displays the results using another function.

    Create another class HybridCalculator and inherit it using these 2 classes:
    Q1. What type of Inheritance are you using?
    Q2. Which mode of Inheritance are you using?
    Q3. Create an object of HybridCalculator and display results of simple and scientific calculator.
    Q4. How is code reusability implemented?
*/

#include<iostream>
#include<cmath>
using namespace std;

class BasicCalc{

protected:
    float num1, num2;
    char opr;

public:
    BasicCalc(void){
        cout<<"We are ready to perform some calulation!!"<<endl
            <<"Here we go!!"<<endl;
    }

    void setData1(float n1, float n2, char op){
        num1 = n1;
        num2 = n2;
        opr = op;
    }
    // void showData(){
    //     cout<<"We will do: "<<num1<<opr<<num2<<endl;
    // }

    void performOpr1(){
        switch (opr)
        {
            case '+':
                cout<<"Your Ans: "<<num1<<'+'<<num2<<" = "<<num1+num2<<endl;
                break;
            case '-':
                cout<<"Your Ans: "<<num1<<'-'<<num2<<" = "<<num1-num2<<endl;
                break;
            case '*':
                cout<<"Your Ans: "<<num1<<'*'<<num2<<" = "<<num1*num2<<endl;
                break;
            case '/':
                cout<<"Your Ans: "<<num1<<'/'<<num2<<" = "<<num1/num2<<endl;
                break;
            default:
                cout<<"I am only able to perform simple calculations!!"<<endl
                    <<"For more try Scientific Calculator"<<endl;
                break;
        }
    }
};

class ScientificCalc: public BasicCalc{

private:
    float nmr;
    int opt;

public:
    ScientificCalc(){
        cout<<"Lets do some complex calulation!!"<<endl;
        cout<<"What do you want to do??"<<endl
            <<"We can perform both basic and complex calcutions!"<<endl
            <<"***************************************************"<<endl;            
        cout<<"01. Basic Calculations"<<endl
            <<"02. Square of a number"<<endl
            <<"03. Square root of a number"<<endl
            <<"04. Cube of a number"<<endl
            <<"05. Cube root of a number"<<endl
            <<"06. log(n) of base e"<<endl
            <<"07. log(n) of base 10"<<endl
            <<"08. log(n) of base 2"<<endl
            <<"09. exponent of a number"<<endl
            <<"10. sin(x), cos(x), tan(x), enter value in degree"<<endl            
            <<"***************************************************"<<endl;            
    }
    void setData2(float nm, int option){
        nmr = nm;
        opt = option;
    }
    void performOpr2(){
        switch (opt)
        {
            case 2:
                cout<<"Square of "<<nmr<<" = "<<(nmr*nmr)<<endl;
                break;
            case 3:
                cout<<"Square root of "<<nmr<<" = "<<pow(nmr, 0.5)<<endl;
                break;
            case 4:
                cout<<"Cube of "<<nmr<<" = "<<(nmr*nmr*nmr)<<endl;
                break;
            case 5:
                cout<<"Cube root of "<<nmr<<" = "<<pow(nmr, (1/3))<<endl;
                break;
            case 6:
                cout<<"Loge("<<nmr<<") = "<<log(nmr)<<endl;
                break;
            case 7:
                cout<<"Log10("<<nmr<<") = "<<log10(nmr)<<endl;
                break;
            case 8:
                cout<<"Log2("<<nmr<<") = "<<(log(nmr)/log(2))<<endl;
                break;
            case 9:
                cout<<"e^"<<nmr<<" = "<<exp(nmr)<<endl;
                break;
            case 10:
                cout<<"sin(x) --> sin"<<nmr<<" = "<<sin(nmr*(3.14159/180))<<endl;
                cout<<"cos(x) --> cos"<<nmr<<" = "<<cos(nmr*(3.14159/180))<<endl;
                cout<<"tan(x) --> tan"<<nmr<<" = "<<tan(nmr*(3.14159/180))<<endl;
                break;
            default:
                cout<<"Please choose from the above options only."<<endl
                    <<"Thanks for trying me!!"<<endl;
                break;
        }
    }
};

int main(){
    
    cout<<"\n~~~~~~Welcome to Calci - where Maths is LOVE!!~~~~~~"<<endl<<endl;
    while(true){
        int choice;
        cout<<"---------------------------------------------------"<<endl
            <<"What type of calcution would you like to perform??"<<endl
            <<"Press 1 for - Simple Calulations"<<endl
            <<"Press 2 for - Scientific Calulations"<<endl
            <<"Press 3 for - EXIT"<<endl
            <<"Your choice: ";
        cin>>choice;
        if (choice == 1){
            float n1, n2;
            char op;
            cout<<"Enter the 1st number: ";
            cin>>n1;
            cout<<"Enter the 2nd number: ";
            cin>>n2;
            cout<<"Enter the operator (+,-,*,/): ";
            cin>>op;
            BasicCalc b1;
            b1.setData1(n1,n2,op);
            // b1.showData();
            b1.performOpr1();
        }
        else if (choice == 2){
            ScientificCalc s;
            int option;
            cout<<"Enter your option: ";
            cin>>option;
            if (option == 1){
                float a,b;
                char o;
                cout<<"Enter the 1st number: ";
                cin>>a;
                cout<<"Enter the 2nd number: ";
                cin>>b;
                cout<<"Enter the operator (+,-,*,/): ";
                cin>>o;
                s.setData1(a, b, o);
                // s.showData();
                s.performOpr1();
            }
            else if (option >= 2 && option <=10){
                float nm;
                cout<<"Enter the number: ";
                cin>>nm;
                s.setData2(nm, option);
                s.performOpr2();
            }
            else
                continue;
        }
        else if (choice == 3){
            exit(0);
        }
        else
            continue;
    }
    
    return 0;
}

// ---------------------------------------Output---------------------------------------

// ~~~~~~Welcome to Calci - where Maths is LOVE!!~~~~~~

// --------------------------------------------------- 
// What type of calcution would you like to perform??  
// Press 1 for - Simple Calulations
// Press 2 for - Scientific Calulations
// Press 3 for - EXIT
// Your choice: 1
// Enter the 1st number: 45
// Enter the 2nd number: 6
// Enter the operator (+,-,*,/): +
// We are ready to perform some calulation!!
// Here we go!!
// Your Ans: 45+6 = 51
// ---------------------------------------------------
// What type of calcution would you like to perform?? 
// Press 1 for - Simple Calulations
// Press 2 for - Scientific Calulations
// Press 3 for - EXIT
// Your choice: 2
// We are ready to perform some calulation!!
// Here we go!!
// Lets do some complex calulation!!
// What do you want to do??
// We can perform both basic and complex calcutions!  
// ***************************************************
// 01. Basic Calculations
// 02. Square of a number
// 03. Square root of a number
// 04. Cube of a number
// 05. Cube root of a number
// 06. log(n) of base e
// 07. log(n) of base 10
// 08. log(n) of base 2
// 09. exponent of a number
// 10. sin(x), cos(x), tan(x), enter value in degree     
// ***************************************************
// Enter your option: 1
// Enter the 1st number: 6
// Enter the 2nd number: 3
// Enter the operator (+,-,*,/): *
// Your Ans: 6*3 = 18
// ---------------------------------------------------
// What type of calcution would you like to perform?? 
// Press 1 for - Simple Calulations
// Press 2 for - Scientific Calulations
// Press 3 for - EXIT
// Your choice: 2
// We are ready to perform some calulation!!
// Here we go!!
// Lets do some complex calulation!!
// What do you want to do??
// We can perform both basic and complex calcutions!
// ***************************************************
// 01. Basic Calculations
// 02. Square of a number
// 03. Square root of a number
// 04. Cube of a number
// 05. Cube root of a number
// 06. log(n) of base e
// 07. log(n) of base 10
// 08. log(n) of base 2
// 09. exponent of a number
// 10. sin(x), cos(x), tan(x), enter value in degree
// ***************************************************
// Enter your option: 8
// Enter the number: 64
// Log2(64) = 6
// ---------------------------------------------------
// What type of calcution would you like to perform??
// Press 1 for - Simple Calulations
// Press 2 for - Scientific Calulations
// Press 3 for - EXIT
// Your choice: 2
// We are ready to perform some calulation!!
// Here we go!!
// Lets do some complex calulation!!
// What do you want to do??
// We can perform both basic and complex calcutions!
// ***************************************************
// 01. Basic Calculations
// 02. Square of a number
// 03. Square root of a number
// 04. Cube of a number
// 05. Cube root of a number
// 06. log(n) of base e
// 07. log(n) of base 10
// 08. log(n) of base 2
// 09. exponent of a number
// 10. sin(x), cos(x), tan(x), enter value in degree
// ***************************************************
// Enter your option: 10
// Enter the number: 30
// sin(x) --> sin30 = 0.5
// cos(x) --> cos30 = 0.866026
// tan(x) --> tan30 = 0.57735
// ---------------------------------------------------
// What type of calcution would you like to perform??
// Press 1 for - Simple Calulations
// Press 2 for - Scientific Calulations
// Press 3 for - EXIT
// Your choice: 3