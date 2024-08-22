
/*
    name= Longest Increasing Subsequence
    link-  https://leetcode.com/problems/longest-increasing-subsequence/
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(n)
    method 1;
*/




class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1);
        int maxLen= INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]= max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]> maxLen) maxLen= dp[i];
        }
        return maxLen;
    }
};