/*
    name= search in rotated sorted array
    link- https://leetcode.com/problems/search-in-rotated-sorted-array/
    author- Parth garg
    time complexity- o(n+logn)
    space complexity-o(1)
    method 1- binary search;
*/


class Solution {
public:
    int binarySearch(vector<int>&nums, int target,int start,int end)
    { 
        int ans= -1;
        int mid= (start+end)/2;
        while(start<=end)
        {
            mid= (start+end)/2;
            if(nums[mid]== target)
            {
                ans= mid;
                break;
            }
            else if(nums[mid]<target)
            {
                start= mid+1;
            }
            else if(nums[mid]>target)
            {
                end= mid-1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int breakPoint=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                breakPoint= i;
            }
        }
        return max(binarySearch(nums,target,0,breakPoint-1),binarySearch(nums,target,breakPoint,nums.size()-1));
        
    }
};