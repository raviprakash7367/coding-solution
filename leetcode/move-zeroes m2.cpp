/*
    name- move zeroes
    link-https://leetcode.com/problems/move-zeroes/
    author- parth garg
    time complexity- o(n)  
    method 2- take 2 variables and use swapping
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        
        //i will iterate the whole array and j stops at the 0's for swapping with nums[i]
        for(int i=0,j=0;i<nums.size();i++)
        {
            if(nums[i]!=0) swap(nums[i],nums[j++]);
        }
        
    }
};