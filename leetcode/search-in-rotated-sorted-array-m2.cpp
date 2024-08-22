/*
    name= search-in-rotated-sorted-array
    link- https://leetcode.com/problems/search-in-rotated-sorted-array/description/
    author- Parth garg
    time complexity- 2*o(logn)
    space complexity- o(1)
    method 1- binary search ;
*/


class Solution {
public:
    int binarySearch(vector<int>&nums, int target,int start,int end)
    { 
        int mid= (start+end)/2;
        while(start<=end)
        {
            mid= (start+end)/2;
            if(nums[mid]== target)
            {
                return mid;
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
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n= nums.size();
        int l=0,r= n-1;
        
        while(l<r)
        {
            int mid= l+ (r-l)/2; 
            if(nums[mid] > nums[n-1]) l= mid+1;
            else r= mid;
        }
   
        if(target> nums[n-1]) return binarySearch(nums,target,0,l-1);
        else return binarySearch(nums,target,l,n-1);
        
    }
};