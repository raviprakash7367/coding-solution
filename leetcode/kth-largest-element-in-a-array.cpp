/*
    name= kth largest element in a array
    link- https://leetcode.com/problems/kth-largest-element-in-an-array/description/
    author- Parth garg
    time complexity- o(nlogk)
    space complexity- o(k)
    method 1- use min heap of size k ;
*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<nums.size();i++)
        {
            if(p.size()==k)
            {
                if(nums[i]>p.top())
                {
                    p.pop();
                    p.push(nums[i]);
                }
            }
            else
            {
                p.push(nums[i]);
            }
        }
        return p.top();

    }
};