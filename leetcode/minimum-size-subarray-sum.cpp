/*
    name= Minimum Size Subarray Sum
    link- https://leetcode.com/problems/minimum-size-subarray-sum/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- 2 pointers;
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int i= 0 , j= 0;
        int sum =0;
        int ans= INT_MAX;
        while(1){
            if(sum<target){
                if(j==n)break;
                sum+= nums[j];
                j++;
            }
            else{
                ans= min(ans, j-i);
                sum-= nums[i];
                i++;
            }
        }

        if(ans== INT_MAX) return 0;
        else return ans;
    }
};