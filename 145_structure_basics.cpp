// A structure is a user-defined data type in C/C++. A structure creates a data type that can be used to group items of possibly different types into a single type. 

// Structures in C++ can contain two types of members:  
//     Data Member: These members are normal C++ variables. We can create a structure with variables of different data types in C++.
//     Member Functions: These members are normal C++ functions. Along with variables, we can also include functions inside a structure declaration.

// typedef is a keyword that is used to assign a new name to any existing data-type. 

#include<iostream>
#include<string>
using namespace std;

struct student{

    // Data Members for struct
    int roll;
    string name;
    float marks;
    
    int age = 14;   //Initialisation of data member can be done. It is Considered as Default Arguments  // It is generally done at the end so that 
        
    // Member Functions
    void printDetails()
    {
        cout<<"Name = "<<name<<", ";
        cout<<"Roll = "<<roll<<", ";
        cout<<"Age = "<<age<<", ";
        cout<<"Marks = "<<marks<<endl;
    }
} st0;   //The variable st is declared along with its data type student

typedef struct teacher{

        int id = 1000;
        string name;

}tch;   //nickname for teacher data type 
        // since we have used typedef so now we can use use tch instead of teacher


int main(){
    
    struct student st1; //Another way of creating a variable of type student in C/C++
    student st2;        //Another way of creating a variable of type student in C++

    st1 = {12, "rahul", 85.63, 14};
    st1.printDetails();

    //No need to paas the value of a default data member if no need to change
    st0 = {1, "raman", 90.63};  
    st0.printDetails();
    
    st2.roll = 22;
    st2.name = "rohan";
    st2.marks = 55;
    st2.age = 15;       //we can modify the default value also for our variable
    st2.printDetails();

    student st_arr[5];  //we can create arrays and use them.
    st_arr[0].roll = 1;
    st_arr[1].roll = 2;
    st_arr[0].name = "nitin";
    st_arr[1].name = "gogo";
    st_arr[0].marks = 72;
    st_arr[1].marks = 73;
    
    for (int i = 0; i < 2; i++){
        cout<<st_arr[i].name<<", "<<st_arr[i].roll<<", "<<st_arr[i].marks<<endl;
    }
    
    teacher t1 = {1001, "sonia"};
    tch t2 = {1002, "shalini"};

    cout<<t1.id<<":\t"<<t1.name<<endl;
    cout<<t2.id<<":\t"<<t2.name<<endl;
    
    tch* ptr = &t1;
    cout<<ptr->id<<":\t"<<ptr->name<<endl;

    return 0;
}

