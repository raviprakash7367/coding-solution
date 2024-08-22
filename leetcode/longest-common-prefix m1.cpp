/*
    name= longest common prefix
    link- https://leetcode.com/problems/longest-common-prefix/
    author- Parth garg
    time complexity- o(n)
    method 1- check for every element in every string 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int minLength=INT_MAX;
        if(strs.size()==1) return strs[0];
        
        for(int i=0;i<strs.size();i--)
        {
            if(minLength > strs[i].length()) minLength= strs[i].length();
        }
        for(int i=0;i<minLength;i++)
        {
            int j;
            for(j = 0; j<strs.size()-1; j++)
            {
                if(strs[j][i]!= strs[j+1][i])
                    break;
                else if(j== strs.size()-2)
                    ans+= strs[j][i];
            }
            if(j!=strs.size()-1) break;
        }
        return ans;    
    }
};
