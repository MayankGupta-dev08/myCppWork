// Given a word and a pattern, we have to find the number of times the anagrams of that pattern may have occurred in the string/word.
// Example 1:
    // Input:
        // txt = forxxorfxdofr
        // pat = for
        // Anagrams of pat: for, orf, ofr, fro, rof, rfo
        // Number of anagrams: n!, n is the no. of distinct char in the pat
        // So, eg- the no. of permutations of for is 3! a1=1,a2=1,a3=1, and n=3 
        // So, eg- the no. of permutations of A,A,A,B,B,C,C,C,C is 9!/(3!*2!*4!) a1=3,a2=2,a3=4, and n=9 
    // Output: 3
        // Explanation: for, orf and ofr appears
        // in the txt, hence answer is 3.

#include <iostream>
#include <string>
#include <map>
using namespace std;

// A Simple C++ program to count anagrams of a pattern in a text.
// TC- O(n*n)

// Function to find if two strings are equal
bool areAnagram(string s1, string s2){
	map<char, int> m;
	for(int i = 0; i < s1.length(); i++)
		m[s1[i]]++;
		
	for(int i = 0; i < s2.length(); i++)
		m[s2[i]]--;
		
	for(auto it = m.begin(); it != m.end(); it++){
		// if(it -> second != 0)
		if((*it).second != 0)
			return false;
    }
	return true;
}

int countAnagrams(string text, string word){
	
	// Initialize result
	int res = 0;
	for(int i = 0; i< text.length()-word.length()+1; i++){  //i<n-k+1
		
		// Check if the word and substring are anagram of each other.
		if (areAnagram(text.substr(i, word.length()), word))
			res++;
	}
	return res;
}


int main(){
	string text = "forxxorfxdofr";
	string patt = "for";
	cout << countAnagrams(text, patt)<<endl;//3
	
	text = "aabaabaa";
	patt = "aaba";
	cout << countAnagrams(text, patt)<<endl;//4
	
	return 0;
}