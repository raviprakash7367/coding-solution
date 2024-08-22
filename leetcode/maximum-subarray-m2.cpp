/*
    name= Maximum subarray
    link- https://leetcode.com/problems/maximum-subarray/
    author- Parth garg
    time complexity- o(n)
    space complexity-o(1)
    method 1- Kadane's algorithm 
*/

class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int sum= 0;
        int maxi= nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+= nums[i];
            maxi= max(sum, maxi);
            if(sum<0) sum= 0;
        }
        return maxi;
    }
};