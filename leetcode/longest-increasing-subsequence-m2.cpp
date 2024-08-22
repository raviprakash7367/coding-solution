
/*
    name= Longest Increasing Subsequence
    link-  https://leetcode.com/problems/longest-increasing-subsequence/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 2;
*/

class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp= {nums[0]};
        for(int i=0;i<n;i++)
        {
            if(nums[i]>dp[dp.size()-1])
                dp.push_back(nums[i]);
            else 
            {
                auto it= lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[it]= nums[i];
            }
        }
        return dp.size();
    }
};