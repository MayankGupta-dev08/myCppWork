// Create a function (Hint: Make it a friend function) which takes 2 point objects and computes the distance between those 2 points

// Use these examples to check your code:
// Distance between (1, 1) and (1, 1) is 0
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

        friend float calcDistance(Point, Point);
};

float calcDistance(Point o1, Point o2){
    float dx2 = ((o2.x-o1.x)*(o2.x-o1.x));
    float dy2 = ((o2.y-o1.y)*(o2.y-o1.y));
    float d = pow((dx2+dy2), 0.5);
    return d;
}

int main(){
    Point p(1, 1);
    Point q(4, 6);

    float dist = calcDistance(p,q);
    cout<<"The distance b/w the point ";
    p.displayPoint();
    cout<<" and point ";
    q.displayPoint();
    cout<<" is: "<<dist<<endl;

    return 0;
}

// ----------------------------Output----------------------------
// The distance b/w the point (1, 1) and point (4, 6) is: 5.83095
