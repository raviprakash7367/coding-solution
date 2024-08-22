/*
    name= detect capital
    link- https://leetcode.com/problems/detect-capital/ 
    author- Parth garg
    time complexity- o(n) n= string length
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    bool detectCapitalUse(string word) { 
        int countCapital=0, countSmall=0;
        for(int i=0;i<word.length();i++)
        {
            if(word[i]-'A'>=0 && word[i]-'Z' <=0)
                countCapital++;
            else countSmall++;
        }
        
        int n= word.length();
        if(countCapital== n || (countCapital==1 && word[0]-'A'>=0 && word[0]-'Z'<=0)) return true;
        else if(countSmall== n) return true;
        else return false;
    }
};