/*
    name= jump game- ii
    link- https://leetcode.com/problems/jump-game-ii/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n)
    method 1- use recursion and memorization -dp;
*/


class Solution {
public:
    int minJumps(vector<int>&nums, vector<int>&dp, int i)
    {
        if(i>=nums.size()-1) return 0;
        if(dp[i]!= 10001) return dp[i];
        for(int j=1;j<=nums[i];j++)
        {
            dp[i]= min(dp[i], 1+minJumps(nums,dp,i+j));
        }
        return dp[i];
    }
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,10001);
        int ans= minJumps(nums,dp,0);
        return ans; 
    }
};