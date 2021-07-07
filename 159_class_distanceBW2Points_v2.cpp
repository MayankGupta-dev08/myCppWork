// Create a function (Hint: Make it a friend function) which takes 2 point objects and computes the distance between those 2 points.

// Use these examples to check your code:
// Distance between (0, 1) and (0, 6) is 5
// Distance between (1, 0) and (70, 0) is 69


#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x, y;
    public:
        Point(int a, int b){
            x = a;
            y = b;
        }

        void displayPoint(){
            cout<<"("<<x<<", "<<y<<")";
        }

        // float calcDistance(Point p2){
        //     float dx2 = ( (p2.x - x)*(p2.x - x) );
        //     float dy2 = ( (p2.y - y)*(p2.y - y) );
            
        //     return (pow((dx2+dy2), 0.5));
        // }

        float calcDistance(Point p2){
            float dx2 = ( (p2.x - this->x)*(p2.x - this->x) );
            float dy2 = ( (p2.y - this->y)*(p2.y - this->y) );
            
            return (pow((dx2+dy2), 0.5));
        }
};


int main(){
    
    int x1,y1, x2,y2;
    cout<<"Enter the x and y coord of your 1st point: ";
    cin>>x1>>y1;
    cout<<"Enter the x and y coord of your 2nd point: ";
    cin>>x2>>y2;
    
    Point p(x1, y1);
    Point q(x2, y2);
   
    cout<<"The distance b/w the point "; p.displayPoint();
    cout<<" and point "; q.displayPoint();
    cout<<" is: "<<p.calcDistance(q)<<endl;

    return 0;
}

// ----------------------------Output----------------------------
// Enter the x and y coord of your 1st point: 1 0
// Enter the x and y coord of your 2nd point: 70 0
// The distance b/w the point (1, 0) and point (70, 0) is: 69

// Enter the x and y coord of your 1st point: 1 1
// Enter the x and y coord of your 2nd point: 4 6
// The distance b/w the point (1, 1) and point (4, 6) is: 5.83095