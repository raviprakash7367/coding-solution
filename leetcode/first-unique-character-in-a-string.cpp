
/*
    name- first unique character in a string
    link-https://leetcode.com/problems/first-unique-character-in-a-string/
    author- Parth garg
    time complexity- o(n)
    method 1- use hashing 
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]-'a']==1) return i;
        }
        return -1;
    }
};