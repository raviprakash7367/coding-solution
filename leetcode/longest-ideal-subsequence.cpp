/*
    name= longest ideal subsequence
    link- https://leetcode.com/problems/longest-ideal-subsequence/
    author- Parth garg
    time complexity- 
    space complexity-o(150*n)
    method 1;
*/



class Solution {
public:
    
    int findMax(string& s,int i,int prev,vector<vector<int>>&dp,int k)
    {
        if(i>=s.length()) return 0;
        
        if(dp[i][prev] != -1) return dp[i][prev];
        
        int ifInclude=0,ifNotInclude=0;
        if(prev==0 || abs(s[i]-prev)<=k)
        {
            ifInclude= 1+findMax(s,i+1,s[i],dp,k);
            
        }
        ifNotInclude= findMax(s,i+1,prev,dp,k);
        
        return dp[i][prev]= max(ifInclude,ifNotInclude);
    }
    
    int longestIdealString(string s, int k) {
        int n= s.length();
        vector<vector<int>>dp(n+1,vector<int>(150,-1));
        int ans= findMax(s,0,0,dp,k);
        return ans;
    }
};