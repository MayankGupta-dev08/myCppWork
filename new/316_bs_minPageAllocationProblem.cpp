/*ALLOCATE MINIMUM NUMBER OF PAGES:
    Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
    There are 3 constraints: 
        1.  Every student should have atleast a book
        2.  Every student is assigned to read some consecutive books.
        3.  Pages of books can't be shared among two or more students. 
    
    Example :
        Input : pages[] = {12, 34, 67, 90}
                m = 2
        Output : 113

        Explanation:
            There are 2 number of students. Books can be distributed 
            in following fashion : 
            1) [12] and [34, 67, 90]
                Max number of pages is allocated to student 
                2 with 34 + 67 + 90 = 191 pages
            2) [12, 34] and [67, 90]
                Max number of pages is allocated to student
                2 with 67 + 90 = 157 pages 
            3) [12, 34, 67] and [90]
                Max number of pages is allocated to student 
                1 with 12 + 34 + 67 = 113 pages

            Of the 3 cases, Option 3 has the minimum pages = 113.
*/

#include <iostream>
#include <climits>
using namespace std;

bool isValid(int arr[], int n, int s, int curr_max){
    if(arr[0]>curr_max)
        return false;
    
    int students=1;
    int curr_sum=0;
    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        if(curr_sum>curr_max){
            students++;
            curr_sum = arr[i];
        }
        if(students>s)
            return false;
    }
    return true;
}

// to minimise the maximum number of pages a student can be allocated
int minPageAllocation(int arr[], int n, int s){
    if(n<s)
        return -1;
    
    long int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];

    int start=0, end=sum;
    int result = INT_MAX;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(isValid(arr, n, s, mid)){
            result = mid;
            end = mid-1;
        }
        else
            start = mid+1;
    }
    return result;
}

int main(){
    //Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int s = 2; //No. of students
 
    cout << "Minimum number of pages = "
         << minPageAllocation(arr, n, s) << endl;
    
    //Number of pages in books
    int arr2[] = {10, 20, 30, 40};
    int n2 = sizeof arr / sizeof arr[0];
    int s2 = 2; //No. of students
 
    cout << "Minimum number of pages = "
         << minPageAllocation(arr2, n2, s2) << endl;
    return 0;
}

// Minimum number of pages = 113
// Minimum number of pages = 60