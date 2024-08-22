/*
    name= delete and earn
    link- https://leetcode.com/problems/delete-and-earn/
    author- Parth garg
    time complexity- o(10^4) ~ o(n)
    space complexity- o(2* 10^4) ~ o(n)
    method 1- make a new array for storing the (total no. of times element repeat * value of element);
*/


class Solution {
public:
    
    int findMax(vector<int>&nums1,int i, vector<int>&dp)
    {
        if(i>= nums1.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        return dp[i]= max(findMax(nums1,i+1,dp), findMax(nums1,i+2,dp)+nums1[i]);
    }
    
    int deleteAndEarn(vector<int>& nums) {
        vector<int>nums1(10001,0);
        for(int i=0;i<nums.size();i++)
        {
            nums1[nums[i]]+= nums[i];
        }
        vector<int>dp(10001,-1);
        return findMax(nums1,0,dp);
    }
};