
/*
    name- find all numbers disappered 
    link- https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
    author- parth garg
    time complexity- o(n)
    method 1- using map 
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>integer;
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            integer[nums[i]]= 1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(integer[i+1]!=1)result.push_back(i+1);
        }
        return result;
        
    }
};