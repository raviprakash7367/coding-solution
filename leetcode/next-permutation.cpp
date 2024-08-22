/*
    name- next permutation
    link- 
    author- Parth garg
    time complexity- o(n)
    method 1- find the breaking point then swap it with just greater integer 
              at right of breaking point and then reverse the array .
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size()-1;
        if(nums.size()<=1) return ;
        int ptr=-1;
        for(int i=n;i>0;i--)
        {
            if(nums[i] > nums[i-1])
            {
                ptr= i-1;
                break;
            }
        }
        if(ptr== -1) 
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n;i>=0;i--)
        {
            if(nums[ptr]< nums[i])
            {
                swap(nums[ptr],nums[i]);
                reverse(nums.begin()+ptr+1, nums.end());
                break;
            }
        }
        return;
    }
};