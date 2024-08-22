/*
    name= Gold Mine Problem
    link- https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1 - dp;
*/

class Solution{
public:
    
    int findMaxGold(vector<vector<int>> &M, int i, int j, vector<vector<int>>&dp)
    {
        int n= M.size();
        int m= M[0].size();
        if(i<0 ) return 0;
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        int up= findMaxGold(M,i-1,j+1, dp);
        int front= findMaxGold(M,i, j+1,dp);
        int down= findMaxGold(M,i+1,j+1, dp);
        return dp[i][j]= M[i][j] + max(up, max(front,down));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            ans= max(ans, findMaxGold(M,i,0,dp));
        }
        return ans;
    }
};