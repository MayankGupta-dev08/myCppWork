#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<utility>
#include<vector>
#include<iterator>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#include<functional>
#include<numeric>

using namespace std;


/********************** NOTE ***************************
// 01.	pair

// Sequence Containers
	// 02.	vector
	// 03.	list
	// 04.	deque

// 05.	stack
// 06.	queue
// 07.	priority queue

// Associative Containers
	// 08.	set
	// 09.	multi set
	// 10.	unordered set
	// 11.	map
	// 12.	multi map
	// 13.	unordered map
*******************************************************/

// Pairs - #include<utility>
void explainPair() {

	pair<int, int> p = {1, 3};
	// prints 1 3
	cout << p.first << " " << p.second<<endl;

	pair<char, int>  g1;         //default
	pair<int, char>  g2(1, 'a');  //initialized,  different data type
	pair<int, int>  g3(1, 10);   //initialized,  same data type
	pair<int, int>  g4(g3);    //copy of g3

    pair <int, char> p1;
    p1.first = 1;
    p1.second = 'a';
	cout << p1.first << " " << p1.second<<endl;

	// Another way to make pair
	pair<string, float> p0;
	p0 = make_pair ("GeeksForGeeks is Best",4.56);


	pair<int, pair<int, int>> p2 = {1, {3, 4}};
	// prints 1 4 3
	cout << p2.first << " " << p2.second.second << " " << p2.second.first<<endl;

	// array of pairs
	pair<int, string> arr[] = { {1, "one"}, {2, "two"}, {5, "three"}};
	cout << arr[1].first<<endl;     // Prints 2
	cout << arr[1].second<<endl;    // Prints two


	// swapping 
	pair<char, int>pair1 = make_pair('A', 1);
    pair<char, int>pair2 = make_pair('B', 2);
 
    cout<<"Before swapping:\n " ;
    cout<<"pair1 = "<< pair1.first <<" "<< pair1.second ;
    cout<<"pair2 = "<< pair2.first <<" "<< pair2.second ;
    pair1.swap(pair2);
    cout<<"\nAfter swapping:\n ";
    cout<<"pair1 = "<< pair1.first <<" "<< pair1.second ;
    cout<<"pair2 = "<< pair2.first <<" "<< pair2.second ;

	// unpacking a pair using tie()
	pair<int, int> Pair1 = { 1, 2 };
    int a, b;
    tie(a, b) = Pair1;
    cout << a << " " << b << "\n";
 
    pair<int, int> Pair2 = { 3, 4 };
    tie(a, ignore) = Pair2;
    // prints old value of b
    cout << a << " " << b << "\n";
 
    // Illustrating pair of pairs
    pair<int, pair<int, char> > Pair3 = { 3, { 4, 'a' } };
    int x, y;
    char z;
     
    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
    x = Pair3.first;
    tie(y, z) = Pair3.second;
    cout << x << " " << y << " " << z << "\n";

}

//Vectors - #include<vectors>
//Vectors - resizeable arrays
void explainVector() {

	// A empty vector
	vector<int> v;  // {} - null vector

    // adds one element at the end
	v.push_back(1); // {1}
	v.emplace_back(2); // {1, 2}
	v.push_back(3); // {1,2,3}
	v.push_back(4); // {1,2,3,4}

    // pops/removes one element from the end
    v.pop_back();   //{1,2,3}
    v.pop_back();   //{1,2}

    //vector of pair
	vector<pair<int, int>> vec; // {{}}

	vec.push_back({1, 2});  // {{1,2}}
	vec.emplace_back(3, 4);  // {{1,2}, {3,4}}

	// Vector of size 5 with every element as 100
	vector<int> v1(5, 100); // {100, 100, 100, 100, 100}

	// A vector of size 5 initialized with 0
	// might take garbage value, dependent on the type vector
	vector<int> v2(5); // {0, 0, 0, 0, 0}

	vector<int> v3(5, 20); // {20, 20, 20, 20, 20}
	vector<int> v4(v3); // {20, 20, 20, 20, 20}


    // iterator is the 3rd thing in stl, apart from containers and algorithms
    // these are objects which acts like pointer to containers

	// Take the vector to be {10, 20, 30, 40}
    // v.begin will point to the 1st element of vector, ie. address and not value
	vector<int>::iterator it = v.begin();

	cout << *(it) << " "<<endl; // prints 10
	it++;
	cout << *(it) << " "<<endl; // prints 2

	it = it + 2;
	cout << (*it) << " "; // prints 40

    // it will point to the memory address after the last element and not the last
	vector<int>::iterator it1 = v1.end();  

    // reverse end will point to the memory address before the first element
	vector<int>::iterator it2 = v1.rend();

    // reverse begin will point to the memory address before the first element
	vector<int>::iterator it3 = v.rbegin();

    //if you don't want your iterators to change its value, use c.begin() or c.end()
    vector<int>::iterator it4 = v.cbegin();
    vector<int>::iterator it5 = v.cend();
    vector<int>::iterator it6 = v.crend();
    vector<int>::iterator it7 = v.crbegin();

    //prints 10 30
	cout << v[0] << " " << v.at(3);

    //prints 40
	cout << v.back() << " "; //for last element, best way if we don't know the size

	// Ways to print the vector

    // way1
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" "; 
    }
    cout<<endl;

    // way2
    vector<int>::iterator itr;
	for (itr = v.begin(); itr != v.end(); itr++) {
		cout << *(itr) << " ";
	}
    cout<<endl;

    //way3 - using auto keyword to auto identify the variable type
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *(it) << " ";
	}

    //way4 - using auto for each element of vector v, so now it will be having values
	for (auto it : v) {
		cout << it << " ";
	}

	// {10, 20, 12, 23}
	v.erase(v.begin()); //earses 1st element

	// {10, 20, 12, 23}
	v.erase(v.begin()+1);   //earses 2nd element

	// {10, 20, 12, 23, 35}
	v.erase(v.begin() + 2, v.begin() + 4); // // {10, 20, 35} [start, end)
    // including the start element (v.begin() + 2) but not the endone (v.begin() + 4)
    //here it dynamically reduces its size

	// *******Insert function*******

	vector<int>v(2, 100);   //2 times 100       // {100, 100}

	v.insert(v.begin(), 300);   //300 at begin       // {300, 100, 100};
	
    // at index1, 2 times 10, others will be pushed
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

	vector<int> copyv(2, 50); // {50, 50}
    // insert copyv at begin, and all copyv vextor
	v.insert(v.begin(), copyv.begin(), copyv.end()); // {50, 50, 300, 10, 10, 100, 100}

	// {10, 20}
	cout << v.size(); // 2

	//{10, 20}
	v.pop_back(); // {10}

	// v1 -> {10, 20}
	// v2 -> {30, 40}
	v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}
	// swap(v1,v2);	//also valid

	v.clear(); // erases the entire vector

	cout << v.empty();  //1 -> empty, 0 -> not empty


	// To get the sum of the vector
	// We use accumulate(), defined in the <numeric> library.
	// #define <numeric>
	int vsum = accumulate(v.begin(), v.end(), 0);
	cout<<vsum;

	// To get Max_element/min_element of the vector
	
	// max_element(v.begin(), v.end()) returns the iterator to the max element in vector
	int mx = *max_element(v.begin(), v.end());
	// min_element(v.begin(), v.end()) returns the iterator to the min element in vector
	int mn = *min_element(v.begin(), v.end());

	// To convert the vector into a prefix sum vector(Quite useful)
	// Example: v = {1,2,3}
	// Prefix_sum v = {1,3,6}
	// converts the vector v into partial sum vector
	partial_sum(v.begin(), v.end(), v.begin());

}


void explainList() {
	list<int> ls;

	ls.push_back(2); // {2}
	ls.emplace_back(4); // {2, 4}

	ls.push_front(5); // {5, 2, 4};

	ls.emplace_front(6); // {6, 5, 2, 4}

    ls.pop_back();  // {6, 5, 2}
    ls.pop_front(); // {5, 2}

	// rest functions same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap
}


// queue - FIFO
// deque - we can remove or add or access from both the sides
// Deque - Double ended queue
void explainDeque() {

	deque<int>dq;
	dq.push_back(1); // {1}
	dq.emplace_back(2); // {1, 2}
	dq.push_front(4); // {4, 1, 2}
	dq.emplace_front(3); // {3, 4, 1, 2}

	dq.pop_back(); // {3, 4, 1}
	dq.pop_front(); // {4, 1}

	cout<<dq.back()<<endl; 

	cout<<dq.front()<<endl;

	// rest functions same as vector
	// begin, end, rbegin, rend, clear, insert, size, swap
}

//stack - LIFO
// if we will push in stavk it will go in front rather in back
// stack doesn't allows to access any other element like vectors does except for the first
// stack we could access only first element or topmost element
// stack has limited functions
void explainStack() {
	stack<int> st;
	st.push(1); // {1}
	st.push(2); // {2, 1}
	st.push(3); // {3, 2, 1}
	st.push(3); // {3, 3, 2, 1}
	st.emplace(5); // {5, 3, 3, 2, 1}

	cout << st.top(); // prints 5  "** st[2] is invalid **"

	st.pop(); // st looks like {3, 3, 2, 1}

	cout << st.top(); // 3

	cout << st.size(); // 4

	cout << st.empty(); //1 if empty and 0 if not

	stack<int>st1, st2;
	st1.swap(st2);

}

// similar to stack as it has limited functionalities
// dynamic in size just like vector, list, deque, stack
// queue - FIFO
void explainQueue() {
	queue<int> q;
	q.push(1); // {1}
	q.push(2); // {1, 2}
	q.emplace(4); // {1, 2, 4}

	q.back() += 5;  // {1,2,9}

	cout << q.back(); // prints 9

	// Q is {1, 2, 9}
	cout << q.front(); // prints 1

	q.pop(); // {2, 9}

	cout << q.front(); // prints 2

	// size swap empty same as stack
}

// priority-queue
// uses the properties of stack and queue
// dynamic in size
// stores the elements in sorted fashion - descending order
// greater the value - higher priority - stores in front
void explainPQ() {
	priority_queue<int>pq;

	pq.push(5); // {5}
	pq.push(2); // {5, 2}
	pq.push(8); // {8, 5, 2}
	pq.emplace(10); // {10, 8, 5, 2}

	cout << pq.top(); // prints 10

	pq.pop(); // {8, 5, 2}  //pops also from top

	cout << pq.top(); // prints 8

	// size swap empty function same as others

    //If we want our priority queue to behave in opposite manner
	// Minimum Heap
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(5); // {5}
	pq.push(2); // {2, 5}
	pq.push(8); // {2, 5, 8}
	pq.emplace(10); // {2, 5, 8, 10}

	cout << pq.top(); // prints 2

    pq.pop();           //pops also from top - {5,8,10}
	cout << pq.top();   // prints 5


}

/*SET, ORDERED SET, UNORDERED SET, MULTISET
	Ordered set
	-	Present in #include <set> header file
	-	it stores only unique elements
	-	automatically sorts in ascending order
	-	Elements are in sorted order
	-	Implemented using balanced BST
	-	Random access is not possible, i.e. you cann't get i'th element in O(1), only thru O(logN)
	
	Multi set
	-	Present in #include <set> header file
	-	can contain duplicates
	-	rest all points are same as that for ordered BST
	-	when erase function is used for a value which has multiple instance than all will be deleted at once
	-	to delete only one/ very first instance of val, we can use ms.erase(ms.find())
	
	** For insertion, deletion and lower/upper_bound, the TC = O(logN) in set (ordered) and muti_set

	Unordered set
	-	Present in #include <unordered_set> header file
	-	it stores only unique elements
	-	elements not in sorted order
	-	random access not possible
	-	implemented using hashing 
	** For insertion and deletion , the TC = O(1) in avg case and O(N) in worst case for unordered_set
	-	we can't implement the lower_bound and upper_bound functions for unordered_set as elements are not in any order
*/
void explainSet() {
	set<int>st;
	st.insert(1); // {1}
	st.emplace(2); // {1, 2}
	st.insert(2); // {1, 2}     //only unique elements
	st.insert(4); // {1, 2, 4}
	st.insert(3); // {1, 2, 3, 4}

	// Functionality of insert in vector
	// can be used also, that only increases
	// efficiency, but it work work ony if we know where to place

	// begin(), end(), rbegin(), rend(), size(),
	// empty() and swap() are same as those of above

	cout<<st.size()<<endl;

	// for printing the element in a set, by default in asc order
	for(auto i: st)
		cout<<i<<" ";
	cout<<"\n";

	// for printing the element in a set, by default in asc order
	for(auto i=st.begin(); i!=st.end(); i++)
		cout<<(*i)<<" ";
	cout<<"\n";

	// for printing the element in a set in reverse order
	for(auto i=st.rbegin(); i!=st.rend(); i++)
		cout<<(*i)<<" ";
	cout<<"\n";

	cout<<*st.lower_bound(2)<<"\n";	//2

	set<int, greater<int>> sett;
	sett.insert(1);
	sett.insert(2);
	sett.insert(3);
	sett.insert(3);
	sett.insert(4);
	// for printing the element in a set, by default in desc order
	for(auto i: sett)
		cout<<i<<" ";
	cout<<"\n";

	// {1, 2, 3, 4, 5}
	auto it = st.find(3);   //it return the index value if found

	// {1, 2, 3, 4, 5}
	auto it = st.find(6);   //it return the index value after the last element
    // ie. it points to end, (not the last but after it)  

    // we can use find to check whether the elemet is present or not
    int ele;
    if(st.find(ele)==st.end())
        cout<<ele<<" is not present!"<<endl;
    else
        cout<<ele<<" is present!"<<endl;

	// {1, 4, 5}
	st.erase(5); // erases 5 // takes logarithmic time
    // {1,4}
	st.erase(st.begin());	//although st.begin() returns an iterator but erase function will work for begin() and end()
	// {4}

    //count() returns 1 if present and 0 if not
	int cnt = st.count(1); 


	auto it = st.find(3);   //it returns the position of 3
	st.erase(it);   //it erases the elemet at it pos 
    // it takes constant time

	// {1, 2, 3, 4, 5}
	auto it1 = st.find(2);
	auto it2 = st.find(4);
	st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

	// lower_bound() and upper_bound() function works in the same way
	// as in vector it does.

	// This is the syntax
	auto it = st.lower_bound(2); 

	auto it = st.upper_bound(3); 
}

void explainMultiSet() {
	// Everything is same as set
	// only stores duplicate elements also
	// sorted in asc order like sets


	multiset<int>ms;
	ms.insert(1); // {1}
	ms.insert(1); // {1, 1}
	ms.insert(1); // {1, 1, 1}

	ms.erase(1); // all 1's erased

	int cnt = ms.count(1); 

	// only a single 1 is erased
	ms.erase(ms.find(1));	//finding pos of first 1 and erasing

	// rest all function same as set
}


// doesn't stores in sorted manner 
void explainUSet() {
	unordered_set<int> st;
	// lower_bound and upper_bound function, does not works
	// rest all functions are same
	// as above,  it does not stores in any
	// particular order it has a better complexity
	// than set in most cases, except some when collision happens
}


// map doesn't store same key value pair twice
// in map if two pair has same key but different values to them than it is allowed - // {1,2} and {1,3}
void explainMap() {

	// {key, value}
	map<int, int> mpp;

	map<int, pair<int, int>> mpp1;

	map< pair<int, int>, int> mpp2;

	// key values can be anything

	mpp[1] = 2;
	mpp.insert({3, 1});
	mpp.insert({2, 4});

	/*It always stores in a sorted manner as per key
	No two keys can be same
	{
		{1, 2}
		{2, 4}
		{3, 1}
	}
	*/
	
	// for map< pair<int, int>, int> mpp2;
	mpp2[{2,3}] = 10; 

	for(auto it : mpp) {
		cout << it.first << " " << it.second << endl; 
	}

	// same options for using iterators
	// as we did in vector for the insert function


	cout << mpp[1]; // prints 2
	cout << mpp[5]; // prints 0, since it does not exists


	auto itr = mpp.find(3); // points to the position where 3 is found
	cout<<(*itr).second; 

	auto it = mpp.find(5); // points to the end of the map since 5 not there

	// lower_bound and upper_bound works exactly in the 
	// same way as it did in set 
    
    // This is the syntax
	auto it = mpp.lower_bound(2); 

	auto it = mpp.upper_bound(3); 

	// erase, swap, size, empty, are same as above 

}


// multimap allows same key value pair more than once
void explainMultimap() {
	// everything same as map, only it can store multiple keys
	// only mpp[key] cannot be used here 
	
}

// map and multimap both stores in a sorted manner but 
// unordered map does not so
// map and multimap - takes logarithmic time
// unordered map takes constant time
void explainUnorderedMap() {
	// same as set and unordered_Set difference. 
}

// this is a custom comparator which which is very useful in sorting
// we can write one as per our reqr

// example1
bool comp(pair<int,int>p1, pair<int,int>p2) {
	if(p1.second < p2.second) {
		return true; 
	} else if(p1.second == p2.second){
		if(p1.first>p2.second) return true; 
	}
	return false; 
}

// example2
bool compar(pair<int, int> p1, pair<int, int> p2){
	if(p1.first<p2.first)
		return true;
	return false;
}


void explainExtra() {

	int n=8, a[n];
	// sorts in asc by default
	sort(a+2, a+4); // [first, last)

	// sorts in dec
	sort(a, a+n, greater<int>());	//#include<functional>
	// The std::greater is a functional object which is used for performing comparisons.
	// This is used for changing the functionality of the given function. Eg- reversing default sorting pattern
	// This can also be used with various standard algorithms such as sort, priority queue, etc. 
    

    pair<int,int> b[] = {{1,2}, {2, 1}, {4, 1}}; 

    // sort it according to second element 
    // if second element is same, then sort 
    // it according to first element but in descending 

	sort(b, b+n ,comp); 

	// {4,1}, {2, 1}, {1, 2}}; 


	int num1 = 7; // 111 
	// __builtin_popcount(num1) - returns the number of set bits in the binary repr of a number
	int cnt = __builtin_popcount(num1); 

	long long num2 = 165786578687;
	int cntt = __builtin_popcountll(num2);


	string s = "123"; 

	do {
		cout << s << endl; 
	} while(next_permutation(s.begin(), s.end())); 
	// It also works for arrays, vectors, lists etc 
	// } while(next_permutation(a,a+n));		//for arrays 


	// 123
	// 132
	// 213
	// 231
	// 312
	// 321
	

	int maxi = *max_element(a,a+n); 
}


int main() {

	return 0;
}
