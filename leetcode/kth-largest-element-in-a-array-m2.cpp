/*
    name= kth largest element in a array
    link- https://leetcode.com/problems/kth-largest-element-in-an-array/description/
    author- Parth garg
    time complexity- o(n)- avg case   o(n^2)- worst case
    space complexity- o(1)
    method 2- using quick select algorithm ;
*/


class Solution {
public:

    int partition(vector<int>&nums, int left, int right)
    {
        int pivot= nums[left];
        int l= left+1;
        int r= right;
        while(l<=r)
        {
            if(nums[l]<pivot && nums[r]>pivot)
            {
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            if(nums[l]>=pivot) l++;
            if(nums[r]<=pivot) r--;
        }
        swap(nums[r],nums[left]);
        return r;

    }

    int findKthLargest(vector<int>& nums, int k) {
        
        int left= 0,right= nums.size()-1;
        while(1)
        {
            int pos= partition(nums,left,right);
            if(pos == k-1) 
            {
                return nums[pos];
            }
            else if(pos<k-1)
            {
                left= pos+1;
            }
            else
            {
                right= pos-1;
            }
        }
        return 0;

    }
};