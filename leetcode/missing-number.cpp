
/*
    Name- missing number
    link- https://leetcode.com/problems/missing-number/
    author-Parth garg
    time complexity- o(n)
    method 1- do the sum of all the numbers and subtract it from n*(n+1)/2 
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int n= nums.size();
        return (n*(n+1)/2)-sum;
    }
};