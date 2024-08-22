/*
    name= number of zero filled subarrays
    link- https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count=0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int temp=0;
            while(i<n && nums[i]==0){
                i++;
                temp++;
            }
            count+= (temp*1LL*(temp+1)/2);
        }
        return count;

    }
};