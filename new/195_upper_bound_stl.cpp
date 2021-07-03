// Iterator lower_bound (Iterator first, Iterator last, const val) 
// Iterator upper_bound (Iterator first, Iterator last, const val) 
// lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’. 
// upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’. 

// lower_bound and upper_bound in vector
#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector

using namespace std;

int main()
{
	int gfg[] = { 5, 6, 7, 7, 6, 5, 5, 6 };

	// creating an array from a vector
    vector<int> v(gfg, gfg + 8); // 5 6 7 7 6 5 5 6

	sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7

	vector<int>::iterator lower, upper;
	lower = lower_bound(v.begin(), v.end(), 6); //memory address of index3
	upper = upper_bound(v.begin(), v.end(), 6); //memory address of index6

	cout << "lower_bound for 6 at position "
		<< (lower - v.begin() + 1) << '\n';     //4
	cout << "upper_bound for 6 at position "
		<< (upper - v.begin() + 1) << '\n';     //7

	return 0;
}
