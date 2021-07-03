// Rules for virtual functions
    // They cannot be static
    // They are accessed by object pointers
    // Virtual functions can be a friend of another class
    // A virtual function in the base class might not be used.
    // If a virtual function is defined in a base class, there is no necessity of redefining it in the derived class


//#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title =  s;
            rating = r;
        }

        // if this was not an virtual function than all 3 times this would have been called, when base class pointer points to either derived class or base class object, but since it is virtual, now it will only be called if pointing to base class object
        virtual void display(){
            cout<<"This is virtual function of base class"<<endl;
            cout<<"Title: "<<title<<endl;
            cout<<"Rating: "<<rating<<endl;
        }
};

class CWHVideo: public CWH
{
    float videoLength;
    public:
        CWHVideo(string s, float r, float vl): CWH(s, r){
            videoLength = vl;
        }
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length of this video is: "<<videoLength<<" minutes"<<endl;
        }
};    

class CWHText: public CWH
{
    int words;
    public:
        CWHText(string s, float r, int wc): CWH(s, r){
            words = wc;
        }
     void display(){
      cout<<"This is an amazing text tutorial with title "<<title<<endl;
      cout<<"Ratings of this text tutorial: "<<rating<<" out of 5 stars"<<endl;
      cout<<"No of words in this text tutorial is: "<<words<<" words"<<endl;
         }
};

int main(){
    string title;
    float rating, vlen;
    int words;

    // for Code With Harry Video
    title = "Django tutorial";
    vlen = 4.56;
    rating = 4.89;
    CWHVideo djVideo(title, rating, vlen);

    // for Code With Harry Text
    title = "Django tutorial Text";
    words = 433;
    rating = 4.19;
    CWHText djText(title, rating, words);

    CWH dj("Django", 4.2);

    CWH* tuts[3];   // pointer array of base class
    tuts[0] = &djVideo;
    tuts[1] = &djText;
    tuts[2] = &dj;

    tuts[0]->display();
    tuts[1]->display();
    tuts[2]->display();

    return 0;
}

// This is an amazing video with title Django tutorial
// Ratings: 4.89 out of 5 stars
// Length of this video is: 4.56 minutes
// This is an amazing text tutorial with title Django tutorial Text
// Ratings of this text tutorial: 4.19 out of 5 stars
// No of words in this text tutorial is: 433 words
// This is virtual function of base class
// Title: Django
// Rating: 4.2