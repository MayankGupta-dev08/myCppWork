#include<iostream>
#include<vector>
#include<stack>
#include<utility>
#include<algorithm>
using namespace std;

vector<int> nearestSmaller2Left(vector<int> v){
    vector<int> ans_v;
    stack<pair<int, int>> st;
    for (int i = 0; i < v.size(); i++){
        if(st.empty())
            ans_v.push_back(-1);
        else if(!st.empty() && st.top().first>=v[i]){
            while(!st.empty() && st.top().first>=v[i])
                st.pop();
            if(st.empty())
                ans_v.push_back(-1);
            else
                ans_v.push_back(st.top().second);
        }
        else
            ans_v.push_back(st.top().second);
    
        st.push({v[i], i});
    }
    return ans_v;   //-1 -1 1 1 3 -1 5
}

vector<int> nearestSmaller2Right(vector<int> v){
    vector<int> ans_v;
    stack<pair<int, int>> st;
    for (int i = v.size()-1; i >=0 ; i--){
        if(st.empty())
            ans_v.push_back(v.size());  //putting index of 1+(index of last element)
        else if(!st.empty() && st.top().first>=v[i]){
            while(!st.empty() && st.top().first>=v[i])
                st.pop();
            if(st.empty())
                ans_v.push_back(v.size());
            else
                ans_v.push_back(st.top().second);
        }
        else
            ans_v.push_back(st.top().second);
    
        st.push({v[i], i});
    }
    reverse(ans_v.begin(), ans_v.end());
    return ans_v;   //1 5 3 5 5 7 7
}


int MAH(vector<int> v){
    vector<int> nsr = nearestSmaller2Right(v);
    vector<int> nsl = nearestSmaller2Left(v);
    
    vector<int> width(v.size());
    for(int i=0; i<v.size(); i++)
        width[i] = nsr[i] - nsl[i] -1;
    // 1 5 1 3 1 7 1

    vector<int> area(v.size());
    int mah = 0;
    for(int i=0; i<v.size(); i++){
        area[i] = v[i]*width[i];
        mah = max(mah, area[i]);
    }   //6 10 5 12 5 7 6
    
    return mah; //12
}

int main(){

    vector<int> v= {6,2,5,4,5,1,6};
    int mah = MAH(v);
    cout<<"Maximum Area of Rectangle in given Histogram: "<<mah<<endl;
    return 0;
}

// Maximum Area of Rectangle in given Histogram: 12