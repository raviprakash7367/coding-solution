/*
    name= third-maximum-number 
    link-https://leetcode.com/problems/third-maximum-number/
    author- Parth garg
    time complexity- o(nlogn)
    method 1- use set 
*/
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>container;
        for(int i=0;i<nums.size();i++)
        {
            container.insert(nums[i]);
        }
        auto it= container.end();
        if(container.size()>=3)
        {
            it--;it--;it--;  
        }
        else 
        {
            it--;
        }
        return *it;
        
    }
};