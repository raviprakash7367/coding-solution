/*
    name= house robber-ii
    link- https://leetcode.com/problems/house-robber-ii/
    author- Parth garg
    time complexity- o(2*n)
    method 1- make 2 dp 1 for index 0 is included and 1 for index 0 is exluded;
*/

class Solution {
public:
    int dp[101];
    // x is lower limit , n= upper limit 
    int maxamt(vector<int>&nums, int n,int x)
    {
        if(n<x) return 0;
        
        if(dp[n]!= -1) return dp[n];
        
        return dp[n]= max(maxamt(nums,n-1,x), maxamt(nums,n-2,x)+nums[n]);
    }
    
    int rob(vector<int>& nums) {
        for(int i=0;i<101;i++)
        {
            dp[i]= -1;
        }
        int ansIncluding0= nums[0] + maxamt(nums,nums.size()-2, 2);
        for(int i=0;i<101;i++)
        {
            dp[i]= -1;
        }
        int ansExcluding0= maxamt(nums,nums.size()-1, 1);
        return max(ansIncluding0,ansExcluding0);
        
    }
};