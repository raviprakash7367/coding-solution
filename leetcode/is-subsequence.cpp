/*
    name= Is subsequence
    link- https://leetcode.com/problems/is-subsequence/
    author- Parth garg
    time complexity- o(n)
    method 1- take a pointer which runs in string s if we find any element same in string s and t  then increase the pointer by 1;
*/


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        
        if(s.size()==0) return true;
        
        for(int i=0;i<t.size();i++)
        {
            if(t[i] == s[j]) j++;
            if(j == s.size()) return true; 
        }   
        return false;
    }
};