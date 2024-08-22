/*
    name= longest common subsequence
    link-https://leetcode.com/problems/longest-common-subsequence/
    author- Parth garg
    time complexity- o(nm)
    space complexity-o(nm)
    method 1- recursion dp bottom up approach;
*/




class Solution {
public:
   
    int LCS(string &text1,string &text2,int m,int n,int dp[1001][1001])
    {
        if(n<=0 || m<=0) return 0;
        
        if(dp[n][m]!= -1) return dp[n][m];
        
        if(text1[n-1]== text2[m-1])
        {
            return dp[n][m]= 1+ LCS(text1,text2,m-1,n-1,dp);
        }
        else
        {
            return dp[n][m]= max(LCS(text1,text2,m-1,n,dp),LCS(text1,text2,m,n-1,dp));
        }
    }    
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        int n= text1.length(), m= text2.length();
        for(int i=0;i<n+1;i++)
            for(int j=0;j<m+1;j++)
                dp[i][j]= -1;
        
        return LCS(text1,text2,m,n,dp);
    }
};