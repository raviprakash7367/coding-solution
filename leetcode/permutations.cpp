/*
    name=  permutations
    link- https://leetcode.com/problems/permutations/description/
    author- Parth garg
    time complexity- O(N! X N)
    space complexity- o(n!* n) where m= size of array
    method 1;
*/



class Solution {
public:
    vector<vector<int>>result;
    void findPermutation(vector<int> &nums, int i)
    {
        if(i== nums.size()) 
        {
            result.push_back(nums);   
            return;
        }
        for(int k=i;k<nums.size();k++)
        {
            swap(nums[i],nums[k]);
            findPermutation(nums,i+1);
            swap(nums[i],nums[k]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        findPermutation(nums,0);
        return result;
    }
};