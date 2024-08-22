
/*
    name=  Number of Longest Increasing Subsequence
    link- https://leetcode.com/problems/number-of-longest-increasing-subsequence/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n)
    method 1- make 2 arrays len[i] contain the maximum length of array which end at i and cnt[i] contains the no. of arrays of which end at ith index with maximum length
*/



class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>len(n,1),cnt(n,1);
        int maxi=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(len[j]+1 == len[i])
                        cnt[i]+= cnt[j];
                    else if(len[j]+1 > len[i])
                    {
                        len[i]= len[j]+1;
                        cnt[i]= cnt[j];
                    }
                }
            }
            maxi= max(maxi,len[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(len[i]==maxi) ans+= cnt[i];
        }
        return ans;
    }
};