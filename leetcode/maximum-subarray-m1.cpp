/*
    name= Maximum subarray
    link- https://leetcode.com/problems/maximum-subarray/
    author- Parth garg
    time complexity- every index is called for its index number of times that is o(n(n+1)/2) = o(n^2)
    space complexity-o(1)
    method 1- use recursion, check for both possibilities what happens if element is taken and if not taken ;
*/

class Solution {
public:
    
    int func(vector<int>& nums, int n, int sum,int count)
    {
        if(n>=nums.size()) 
        {   if(count==0)
                return nums[n-1];
            else
                return sum;
        }
        
        if(sum!=0)
            return max(func(nums,n+1, sum+nums[n],count+1), sum);
        else
            return max(func(nums,n+1, sum+nums[n],count+1), func(nums,n+1,0,count));            
    }
    
    int maxSubArray(vector<int>& nums) {
        return func(nums,0,0,0);
    }
};