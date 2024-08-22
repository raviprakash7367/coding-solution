/*
    name= kth largest element in a array
    link- https://leetcode.com/problems/kth-largest-element-in-an-array/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 3- hashing ;
*/


class Solution {
public:
 

    int findKthLargest(vector<int>& nums, int k) {
        int arr[20001]={0};

        for(int i=0;i<nums.size();i++)
        {
            arr[nums[i]+10000]++;
        }
        int count=0;
        for(int i= 20000;i>=0;i--)
        {
            count+= arr[i];
            if(count>=k)return i-10000;
        }
        return 0;

    }
};
