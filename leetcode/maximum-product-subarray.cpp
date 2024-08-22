/*
    name= maximum product subarray
    link-https://leetcode.com/problems/maximum-product-subarray/
    author- Parth garg
    time complexity- o(n)
    space complexity-o(1)
    method 1;
*/



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res= nums[0];
        int maxi= nums[0],mini=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(maxi,mini);
            
            maxi= max(nums[i],maxi*nums[i]);
            mini= min(nums[i],nums[i]*mini);
            
            res= max(res,maxi);
        }
        return res;
    }
};