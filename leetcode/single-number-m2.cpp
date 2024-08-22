/*
    ques name- sqrt(x)
    link- https://leetcode.com/problems/single-number/
    author- parth garg
    time complexity = 
    method 2- using XOR 

*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans= ans^nums[i];
        }
        return ans;
    }
};