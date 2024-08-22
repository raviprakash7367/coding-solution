/*
    name= Single Element in a Sorted Array
    link-  https://leetcode.com/problems/single-element-in-a-sorted-array/description/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(1)
    method 1- binary search;
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r= nums.size()-1;
        int n= nums.size();
        while(l<r)
        {
            int mid= l+ (r-l)/2;

            if(mid+1<n && nums[mid]== nums[mid+1] )
            {
                if( mid %2==1) r= mid-1;
                else l= mid+2;

            }
            else if(mid-1>=0 && nums[mid]== nums[mid-1])
            {
                if( mid %2==1) l=mid+1;
                else r= mid-2;
            }
            else return nums[mid];
        }
        return nums[l];
    }
};