/*
    name= coin change-ii
    link-https://leetcode.com/problems/coin-change-ii/
    author- Parth garg
    time complexity- o(n*amount)
    space complexity- o(n*amount)
    method 1- dp[i][j]= number of ways to make sum = j when array size is i (0 to ith index)
*/


class Solution {
public:
    
    int count(vector<int>&coins,int i,int j, vector<vector<int>>&dp)
    {
        if(i==0 && j==0) return 0;
        else if(i==0) return 0;
        else if(j==0) return 1;
        
        if(dp[i][j]!= -1) return dp[i][j];
        if(coins[i-1]<= j)
        {
            return dp[i][j]= count(coins,i-1,j,dp) + count(coins,i,j-coins[i-1],dp);
        }
        else
        {
            return dp[i][j]= count(coins,i-1,j,dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n= coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));

        return count(coins,n,amount,dp);
    }
};