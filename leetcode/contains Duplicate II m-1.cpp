/*
    Name- Contains-Duplicate II
    link- https://leetcode.com/problems/contains-duplicate-ii/submissions/
    author-Parth garg
    time complexity- o(n)
    method 1- using map (Faster than 74 % )
*/



class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>m;
        int size= nums.size();
        for(int i=0;i<size;i++)
        {
            m[nums[i]].push_back(i);
            if(m[nums[i]].size()>=2) 
            {
                // n is length of value vector of key nums[i]
                int n= m[nums[i]].size();
                if(m[nums[i]][n-1]-m[nums[i]][n-2]  <=k) return true;
            }
        }
        return false;
    }
};