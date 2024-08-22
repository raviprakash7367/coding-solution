/*
    name= maximum profit
    link- https://practice.geeksforgeeks.org/problems/maximum-profit4657/1
    author- Parth garg
    time complexity- o(n*k*2) = o(n*k)
    space complexity- o(n*k*2) = o(n*k)
    method 1;
*/

class Solution {
  public:
    
    int solve(vector<vector<vector<int>>>&dp , int i, int buy, int limit, int A[],int n){
        if(i>=n) return 0;
        if(limit == 0) return 0;
        
        if(dp[i][buy][limit] != -1) return dp[i][buy][limit];
        
        int profit= 0;
        if(buy){
            int buykaro= -A[i] + solve(dp, i+1, 0, limit, A, n);
            int skipkaro= solve(dp,i+1,1,limit, A,n);
            profit= max(buykaro,skipkaro);
        }
        else{
            int sellkaro= A[i] + solve(dp, i+1,1,limit-1,A,n);
            int skipkaro= solve(dp, i+1, 0, limit, A, n);
            profit= max(sellkaro,skipkaro);
        }
        return dp[i][buy][limit] = profit;
    }
  
    int maxProfit(int K, int N, int A[]) {
        vector<vector<vector<int>>>dp (N,vector<vector<int>>(2, vector<int>(K+1,-1)));
        return solve(dp,0,1,K,A,N);
    }
};