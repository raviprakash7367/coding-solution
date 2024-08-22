/*
    name- valid-palindrome
    link- https://leetcode.com/problems/valid-palindrome/
    author- Parth garg
    time complexity- o(n)
    method 1: convert the string to alphanumeric string and 
             remove all other characters and then check palindrome
*/


class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++)
        {
            if((s[i]>=97 && s[i]<= 122) || (s[i]>=48 && s[i]<=57)) continue;
            else if(s[i]>=65 && s[i]<=90)
            {
                s[i]= s[i]-65+97;
            }
            else
            {
                s.erase(i,1);
                i--;
            }
        }
        int len= s.length();
        for(int i=0;i<len/2;i++)
        {
            if(s[i]!=s[len-1-i]) return false;
        }
        return true;
    }
};