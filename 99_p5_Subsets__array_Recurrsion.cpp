// To write a program ..to geneate all possible subsets of a given set, where set is a collection of distinct elements, so no duplicates.
    // For an array of n elements, we will have 2 ki power n. 
    // 2 ki power n -->  1<<n, for n =4  --> 1<<4 = 10000 = 16 


// this problem aka - all subsets - power set - all subsequenses

#include <iostream>
using namespace std;

// using recurrsion
void subSets_recurr(int ip_arr[], int n, int i_pos,int op_arr[], int curr_op_n){

    // checking if all elements of the array are traverse or not
    if (i_pos==n){
        for (int i = 0; i < curr_op_n; i++){
            cout<<op_arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    // for each index i_pos, we have 2 options - 
    // case 1: i_pos is not included in the subset in this case simply increment i and move ahead
    // case 2: i_pos is included in the subset, so insert ip_arr[i] at the end of subset & increment i_pos and curr_op_n

    subSets_recurr(ip_arr, n, (i_pos+1),op_arr,curr_op_n);    //choice 1  

    op_arr[curr_op_n] = ip_arr[i_pos];
    subSets_recurr(ip_arr, n, (i_pos+1),op_arr,(curr_op_n+1));  //choice 2

    return;
}


int main(){

    int ip_arr[] = {1,2,3,4};   //input array
    int n = 4;                  // size of arr 
    int i_pos = 0;              //ith index of input array 
    int op_arr[100];            //array to store the subset
    int curr_op_n = 0;          // current size of subset
    
    subSets_recurr(ip_arr, n, i_pos, op_arr, curr_op_n);
    return 0;
}

// 
// 4 
// 3 
// 3 4 
// 2 
// 2 4 
// 2 3 
// 2 3 4 
// 1 
// 1 4 
// 1 3 
// 1 3 4 
// 1 2 
// 1 2 4 
// 1 2 3 
// 1 2 3 4