/*
    name= rearrange array elements by sign
    link- https://leetcode.com/problems/rearrange-array-elements-by-sign/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- split given array in 2 containing positive and negative respectively and then merge them;
*/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive,negative;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0) negative.push_back(nums[i]);
            else positive.push_back(nums[i]);
        }
        
        nums.clear();
        for(int i=0;i<n/2;i++)
        {
            nums.push_back(positive[i]);
            nums.push_back(negative[i]);
        }
        return nums;
    }
};