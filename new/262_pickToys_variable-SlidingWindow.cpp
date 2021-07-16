// John is at a toy store help him pick maximum number of toys. He can only select in a continuous manner and he can select only two types of toys.

#include <iostream>
#include <map>
using namespace std;

// longest subarray with at most two different toys
int pickToys(char arr[], int n){
    map<char, int> mp;
    int ans=0, i=0, j=0;
    while(j<n){
        mp[arr[j]]++;
        if(mp.size()<=2)
            ans=max(ans, j-i+1);
        else if(mp.size()>2){
            while(mp.size()>2){
                mp[arr[i]]--;
                if(mp[arr[i]]==0)
                    mp.erase(arr[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main(){
    char set1[] = {'a','b','c','c','c','b','a','c'};
    int n = sizeof(set1)/sizeof(set1[0]);
    cout<<pickToys(set1,n)<<endl;           //5

    char set2[] = {'a','b','a'};
    n = sizeof(set2)/sizeof(set2[0]);
    cout<<pickToys(set2,n)<<endl;           //3

    char set3[] = {'a','a','a','a'};
    n = sizeof(set3)/sizeof(set3[0]);
    cout<<pickToys(set3,n)<<endl;           //4

    char set4[] = {'a','b','b','c'};
    n = sizeof(set4)/sizeof(set4[0]);
    cout<<pickToys(set4,n)<<endl;           //3

    char set5[] = {'a','b','c','b','b'};
    n = sizeof(set5)/sizeof(set5[0]);
    cout<<pickToys(set5,n)<<endl;           //4
    return 0;
}