/*
    name= Minimum Limit of Balls in a Bag
    link- https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    int operations(vector<int>&nums, int x){
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=x) continue;
            count+= (nums[i]/x);
            if(nums[i]%x==0) count--;
        }
        return count;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l= 1,r= 1e9;
        while(l<r){
            int mid= l+ (r-l)/2;
            if(operations(nums,mid) > maxOperations){
                l= mid+1;
            }
            else{
                r= mid;
            }
        }
        return l;
    }
};