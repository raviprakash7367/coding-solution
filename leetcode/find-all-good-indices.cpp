/*
    name= find all good indices
    link-https://leetcode.com/problems/find-all-good-indices/
    author- Parth garg
    time complexity- o(n)
    space complexity-o(n)
    method 1- precompute the length sorted before index and after index;
*/


class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>result;
        vector<int>leftSortedLength(n,1),rightSortedLength(n,1);
        
        for(int i=1;i<n;i++)
            if(nums[i]<= nums[i-1])leftSortedLength[i]= leftSortedLength[i-1]+1 ;
        for(int i=n-2;i>=0;i--)
           if(nums[i]<= nums[i+1]) rightSortedLength[i]=rightSortedLength[i+1]+1;
        for(int i= k;i<n-k;i++)
        {
            if(leftSortedLength[i-1]>= k && rightSortedLength[i+1]>=k)
                result.push_back(i);
        }
        return result;
    }
};