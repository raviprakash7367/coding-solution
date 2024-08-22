/*
    name- ransom note
    link-https://leetcode.com/problems/ransom-note/
    author- Parth garg
    time complexity- o(n)
    method 1- use hashing 
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomFreq[26]={0};
        int magazineFreq[26]= {0};
        
        // ransomNote can be constructed by using the letters from magazine
        
        if(magazine.length()< ransomNote.length()) 
            return false;
        
        for(int i=0;i<ransomNote.length();i++)
        {
            ransomFreq[ransomNote[i]-'a'] ++;
        }
        for(int i=0;i<magazine.length();i++)
        {
            magazineFreq[magazine[i]-'a'] ++;
        }
        for(int i=0;i<26;i++)
        {
            if(ransomFreq[i]> magazineFreq[i]) 
                return false;
        }
        return true;
        
    }
};