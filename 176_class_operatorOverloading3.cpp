// subscript operator overloading

#include <iostream>
using namespace std;

class sample{
    private:
        int arr[5];

    public:
        sample(){
            for (int i = 0; i < 5; i++)
                arr[i] = 100+i;
        }

        int operator[](int k){  //subscript operator overloading
            if(k>=5)
                return -1;
            return arr[k];
        }
};

int main(){
    sample s1;
    cout<<s1[0]<<endl;  //100
    cout<<s1[1]<<endl;  //101
    cout<<s1[3]<<endl;  //103
    cout<<s1[5]<<endl;  //-1
    cout<<s1[7]<<endl;  //-1
    return 0;
}