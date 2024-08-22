/*
    name= longest palindromic subsequence
    link- https://leetcode.com/problems/longest-palindromic-subsequence/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1- find the string b by reversing the string a and then find the longest common subsequence between both;
*/


class Solution {
public:
    
    int LCS(string &a, string &b, int i,int j, vector<vector<int>> &dp)
    {
        if(i<=0 || j<=0)return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(a[i-1]== b[j-1])
        {
            return dp[i][j]= 1+ LCS(a,b,i-1,j-1,dp);
        }
        else
            return dp[i][j]= max(LCS(a,b,i-1,j,dp), LCS(a,b,i,j-1,dp));
    }
    
    int longestPalindromeSubseq(string a) {
        int n= a.length();
        string b="";
        for(int i= n-1;i>=0;i--)
            b+= a[i];
        
        vector<vector<int>>dp(n+1,vector<int>(n+1, -1));
        return LCS(a,b,n,n,dp);
        
    }
};