/*
    name- valid anagram 
    link- https://leetcode.com/problems/valid-anagram/
    author- parth garg
    time complexity- o(n)
    method 1- use hashing / we can use unordered map also for saving freq. of alphabets
*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqS[26]={0};
        int freqT[26]={0};
        for(int i=0;i<s.length();i++)
        {
            freqS[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++)
        {
            freqT[t[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freqS[i]!= freqT[i]) return false;
        }
        return true;
    }
};