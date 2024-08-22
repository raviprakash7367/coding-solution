/*
    name= largest-positive-integer-that-exists-with-its-negative
    link-https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1- use two pointer;
*/



class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r= nums.size()-1;
        while(l<r)
        {
            if(nums[l]+nums[r]==0)
                return nums[r];
            else if(nums[l]+nums[r]<0)
                l++;
            else r--;
        }
        return -1;
    }
};