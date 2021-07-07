// The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val. This means that the function returns the index of the next smallest number just greater than or equal to that number. If there are multiple values that are equal to val, lower_bound() returns the index of the first such value.

// Time Complexity:  The number of comparisons performed is logarithmic. Therefore, the time complexity of the above approach is O(logN), where N = size.

// CPP program to illustrate
// std :: lower_bound
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // for arrays
    int a[] = {1,4,5,6,9,9};
    int size = 6;
    cout<<"Array contains:"<<endl;
    for (int i = 0; i < size; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    int l1,l2,l3;
    l1 = lower_bound(a,a+size,4) - a;
    l2 = lower_bound(a,a+size,7) - a;
    l3 = lower_bound(a,a+size,10) - a;

    // Printing the lower bounds
	cout<< "\nlower_bound for element 4 at position : "<<l1<<endl;
	cout<< "\nlower_bound for element 7 at position : "<<l2<<endl;
	cout<< "\nlower_bound for element 10 at position : "<<l3<<endl;

	// Input vector
	vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };

	// Print vector
	cout << "Vector contains :";
	for (unsigned int i = 0; i < v.size(); i++)
		std::cout << " " << v[i];
	cout << "\n";

	vector<int>::iterator low1, low2, low3;
	
	// std :: lower_bound
	low1 = lower_bound(v.begin(), v.end(), 30);
	low2 = lower_bound(v.begin(), v.end(), 35);
	low3 = lower_bound(v.begin(), v.end(), 55);

	// Printing the lower bounds
	cout<< "\nlower_bound for element 30 at position : "
		<< (low1 - v.begin());
	cout<< "\nlower_bound for element 35 at position : "
		<< (low2 - v.begin());
	cout<< "\nlower_bound for element 55 at position : "
		<< (low3 - v.begin());

	return 0;
}
