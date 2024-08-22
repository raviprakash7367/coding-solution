/*
    name= Subsets II
    link- https://leetcode.com/problems/subsets-ii/description/
    author- Parth garg
    time complexity- O(2^n)
    space complexity- O(2^n * k) to store every subset of average length k.
                      Auxiliary space is O(n)  if n is the depth of the recursion tree.
    method 2;
*/




class Solution {
public:
    vector<vector<int>>result;
    void subset(vector<int>& nums, int ind,vector<int>temp)
    {
        result.push_back(temp);

        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            subset( nums,i+1, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        vector<int>temp;
        subset(nums,0,temp);
        
        return result;
    }
};