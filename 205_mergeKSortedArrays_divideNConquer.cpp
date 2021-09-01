/*Merge k sorted arrays
    Given k sorted arrays of size n each, merge them and print the sorted output.
    Input: k = 3, n = 4 
        arr[][] = { {1, 3, 5, 7}, 
        {2, 4, 6, 8}, 
        {0, 9, 10, 11}} ;
    Output: 0 1 2 3 4 5 6 7 8 9 10 11 
    
    Approach2: The process might begin with merging arrays into groups of two. After the first merge, we have k/2 arrays. Again merge arrays in groups, now we have k/4 arrays. This is similar to merge sort. Divide k arrays into two halves containing an equal number of arrays until there are two arrays in a group. This is followed by merging the arrays in a bottom-up manner. 
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define n 4

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int arr3[]){
    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j])
            arr3[k++]=arr1[i++];
        else
            arr3[k++]=arr2[j++];
    }
    while(i<n1)
        arr3[k++]=arr1[i++];
    
    while(j<n2)
        arr3[k++]=arr2[j++];
}

void mergeKSortedArrays(int arr[][n], int i, int j, int res[]){
    if(i==j){   //only 1 array
        for (int m = 0; m < n; m++)
            res[m]=arr[i][m];        
        return;
    }
    if(j==i+1){  //only 2 arrays
        mergeArrays(arr[i], n, arr[j], n, res);
        return;
    }
    // creating output arrays
    int n1=n*(((i+j)/2)-i+1), n2=n*(j-((i+j)/2));
    int otp1[n1], otp2[n2];

    // dividing the arrays into two halves
    mergeKSortedArrays(arr, i, (i+j)/2, otp1);
    mergeKSortedArrays(arr, (i+j)/2+1, j, otp2);

    // merging the arrays
    mergeArrays(otp1, n1, otp2, n2, res);
}

void printArray(int a[], int sz){
    for (int i = 0; i < sz; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main(){
    int k=3; // n=4 and k=3 --> 3 arrays of size 4 each
    int arr[k][n] = {{2, 6, 12, 19},
                     {1, 9, 20, 95},
                     {5, 8, 23, 27}};

    int res[n*k];
    int first=0, last=k-1;
    cout<<"Merged array:-\n";
    mergeKSortedArrays(arr, first, last, res);
    printArray(res, n*k);
    return 0;
}

// 1 2 5 6 8 9 12 19 20 23 27 95 