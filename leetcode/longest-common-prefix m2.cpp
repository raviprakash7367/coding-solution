/*
    name= longest common prefix
    link- https://leetcode.com/problems/longest-common-prefix/
    author- Parth garg
    time complexity- o(nmlogn)
    method 2- use sorting
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans;
        int minLength = min(strs[0].length(),strs[strs.size()-1].length());
        for(int i=0;i<minLength;i++)
        {
            if(strs[0][i]== strs[strs.size()-1][i]) 
                ans+=strs[0][i];
            else break;
        }
        return ans;
        
    }
};
