/*
    name= optimal partition of string 
    link- https://leetcode.com/problems/optimal-partition-of-string/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    int partitionString(string s) {
        int count =0;
        int n= s.length();
        for(int i=0;i<n;){
            unordered_map<char,int>mp;
            while(i<n && mp[s[i]] == 0){
                mp[s[i]]++;
                i++;
            }
            count++;
        }
        return count;
    }
};