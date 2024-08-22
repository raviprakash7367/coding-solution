/*
    name= Optimal Strategy For A Game
    link- https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1;
*/

class Solution{
    public:
    
    int solve(vector<vector<int>>&dp, int arr[], int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        
        return dp[i][j]= max( (arr[i] + min(solve(dp,arr,i+2,j), solve(dp,arr,i+1,j-1))), (arr[j] + min(solve(dp,arr,i,j-2),solve(dp,arr,i+1,j-1))));
    }
    
    long long maximumAmount(int arr[], int n){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(dp,arr,0,n-1);
    }
};