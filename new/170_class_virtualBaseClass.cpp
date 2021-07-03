#include<iostream>
using namespace std;
/*
Inheritance:
student -->test [Done]
student-->sports [Done]
test --> result [Done]
sports --> result [Done]
*/

class Student{
    protected:
        int roll_no;
    public:
        void set_number(int a){
            roll_no = a;
        }
        void print_number(void){
            cout<<"Your roll no is "<< roll_no<<endl;
        }
};

class Test : virtual public Student{
    protected:
        float maths, physics;
        public:
            void set_marks(float m1, float m2){
                maths = m1;
                physics = m2;
            }

            void print_marks(void){
                cout << "You result is here: "<<endl
                     << "Maths: "<< maths<<endl
                     << "Physics: "<< physics<<endl;
            }
};

class Sports: public virtual Student{
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        }

        void print_score(void){
            cout<<"Your PT score is "<<score<<endl;
        }

};

class Result : public Test, public Sports{
    private:
        float total;
        float percentage;
    public:
        void display(void){
            total = maths + physics + score;
            percentage = ((maths + physics + score)/210)*100;
            print_number();
            print_marks();
            print_score();
            cout<< "Your total score is: "<<total<<endl;
            cout<< "Your total percentage is: "<<percentage<<'%'<<endl;
        }
};


int main(){
    Result mannu;
    mannu.set_number(21);
    mannu.set_marks(84.9, 99.5);
    mannu.set_score(9);
    mannu.display();
    return 0;
}

// -----------Output-----------
// Your roll no is 21
// You result is here: 
// Maths: 84.9
// Physics: 99.5
// Your PT score is 9
// Your total score is: 193.4        
// Your total percentage is: 92.0952%