
/*
    name= Remove Duplicates from Sorted Array II
    link- https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
    author- Parth garg 
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
        
    return i;
}
};