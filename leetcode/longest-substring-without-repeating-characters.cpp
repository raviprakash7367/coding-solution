
/*
    name= longest substring without repeating characters
    link- https://leetcode.com/problems/longest-substring-without-repeating-characters/
    author- Parth garg
    time complexity- o(n)
    method 1- take 2 pointers and use one pointer for inserting elements 
    in set and if element is already present in set then use another pointer 
    to delete that element from the set;
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n= s.length();
        unordered_set<int>st;
        int ans= 0;
        while(i<n && j<n)
        {
            if(st.find(s[j])== st.end())
            {
                st.insert(s[j]);
                j++;
                ans= max(ans, j-i);
            }
            else
            {
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};