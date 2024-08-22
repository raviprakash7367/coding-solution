/*
    ques name- majority-element
    link- https://leetcode.com/problems/majority-element/
    author- parth garg
    time complexity = o(nlogn)
    method 1- using map 

*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>countFreq;
        for(int i=0;i<nums.size();i++)
        {
            countFreq[nums[i]]++;
            if(countFreq[nums[i]]> nums.size()/2)
            {
                return nums[i];
            }
        }
        return 0;
    }
};