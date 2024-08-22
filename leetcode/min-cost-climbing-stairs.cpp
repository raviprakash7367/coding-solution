/*
    name=  min cost climbing stairs
    link- https://leetcode.com/problems/min-cost-climbing-stairs/
    author- Parth garg
    time complexity- o(n)
    method 1- use DP;
*/
class Solution {
public:
    int recursion(vector<int>&cost, int step,vector<int>&dp)
    {
        if(step >= cost.size()) return 0;
        if(dp[step]!=-1) return dp[step];
        
        int st1= recursion(cost, step+1,dp)+ cost[step];
        int st2= recursion(cost, step+2,dp)+ cost[step];
        return dp[step]= min(st1,st2);
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        
       int x= min(recursion(cost, 0,dp),recursion(cost,1,dp));
        return x;
    }
};