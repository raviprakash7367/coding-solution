/*
    name- reverse-string
    link- https://leetcode.com/problems/reverse-string/submissions/
    author-Parth garg
    time complexity= o(n/2) or o(n)
    method 1- use swapping n/2 time in place of inbuilt reverse function 
*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i< s.size()/2;i++)
        {
            swap(s[i],s[s.size()-1-i]);
        }
        return;
    }
};