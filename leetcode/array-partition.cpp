
/*
    name= array partition
    link- https://leetcode.com/problems/array-partition/
    author- Parth garg
    time complexity- o(n)
    space complexity-o(1)
    method 1;
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i=i+2)
            ans+= nums[i];
        return ans;
    }
};