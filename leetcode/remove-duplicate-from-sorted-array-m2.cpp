/*
    name= Remove Duplicates from Sorted Array
    link- https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[j]!= nums[j-1])
            {
                nums[i]= nums[j];
                i++;
            }
        }
        return i;
    }
};