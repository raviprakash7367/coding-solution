/*
    name= Subsets II
    link- https://leetcode.com/problems/subsets-ii/description/
    author- Parth garg
    time complexity-  O( 2^n *(k log (x) )). 2^n   
    space complexity- O(2^n * k)
    method 1;
*/


class Solution {
public:
    set<vector<int>>s;
    void subset(vector<int>& nums, int i,vector<int>temp)
    {
        if(i== nums.size())
        {
            if(s.count(temp)==0) 
            {
                s.insert(temp);
            }
            return ;
        }
        subset(nums,i+1, temp);
        temp.push_back(nums[i]);
        subset(nums,i+1,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        subset(nums,0,temp);
        for(auto vec : s)
        {
            result.push_back(vec);
        }
        return result;
    }
};