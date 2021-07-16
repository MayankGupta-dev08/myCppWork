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

// TC : O(n)
// SC : O(distinctChars(ana))
int countOccurrence_Anagrams(string word, string patt){
    map<char,int> dist_chars;   //of patt
    for (int i = 0; i < patt.size(); i++){
        dist_chars[patt[i]]++;
    }
    //so that we don't have to traverse map, everytime we want to check
    int count=dist_chars.size();
    int i=0, j=0, k=patt.length(), ans=0;
    while(j<word.length()){
        if(dist_chars.find(word[j])!=dist_chars.end()){
            dist_chars[word[j]]--;
            if(dist_chars[word[j]]==0)
                count--;
        }
        if(j-i+1==k){
            if(count==0)
                ans++;
            if(dist_chars.find(word[i])!=dist_chars.end()){
                if(dist_chars[word[i]]==0)
                    count++;
                dist_chars[word[i]]++;
            }
            i++;
        }
        j++;
    }

    return ans;
}

int main(){
    string s = "forxxorfxdofr";
    string ana = "for";
    cout<<countOccurrence_Anagrams(s, ana)<<endl; //3

    s = "aabaabaa";
    ana = "aaba";
    cout<<countOccurrence_Anagrams(s, ana)<<endl; //4
    return 0;
}

// Main idea-
    // Generate a map of all character occurances of the 2nd string, i.e char and its count.
    // The window size becomes the length of 2nd string, as the anangrams wil also be of this length, amd another variable count denotes the distinct characters left in a sliding window.
    // In a window if the current character is present in map, then decrease its count, and if the count becomes 0, decrease the 'count' variable.
    // If the window size is lesser than k just move forward the window
    // When the window is hit ->
    // If the count is 0, it means all the characters needed for its anagram is here in it, therefore increase your answer
    // To remove the last part (arr[i] part) so that the window can be shifted ->
    // If the s[i] is present in map then increase its count and if it changes from 0->1 then increase the 'count' variable