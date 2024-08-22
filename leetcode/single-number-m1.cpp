/*
    ques name- sqrt(x)
    link- https://leetcode.com/problems/single-number/
    author- parth garg
    time complexity = o(n)
    method 1- hashing
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr[60001]={0};
        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]+30000]++;
        }
        for(int i=0;i<60001;i++)
        {
            if(arr[i]==1)
            {
                return (i-30000);
            }
        }
        return 0;
    }
};