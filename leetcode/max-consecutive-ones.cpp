/*
    name- max-consecutive-ones
    link- https://leetcode.com/problems/max-consecutive-ones/
    author- Parth garg
    time complexity- o(n)
    method 1
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1s=0;
        int j;
        for(int i=0;i<nums.size();i=j)
        {
            int temp=0;
            for(j=i;j<nums.size();j++)
            {
                if(nums[j]==0) break;
                else temp++;
            }
            max1s= max(max1s, temp);
            if(j!= nums.size() && nums[j]==0) j++;
        }
        return max1s;
    }
};