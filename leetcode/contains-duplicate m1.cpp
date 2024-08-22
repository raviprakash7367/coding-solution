/*
    ques name- contains-duplicate
    link- https://leetcode.com/problems/contains-duplicate/
    author- parth garg
    time complexity = o(nlogn)
    method 1- using set

*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>singleNumbers;
        for(int i=0;i<nums.size();i++)
        {
            int sizeOfSet= singleNumbers.size();
            singleNumbers.insert(nums[i]);
            if(sizeOfSet== singleNumbers.size()) return true;
        }
        return false;
    }
};