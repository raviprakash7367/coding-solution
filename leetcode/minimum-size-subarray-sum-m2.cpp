/*
    name= Minimum Size Subarray Sum
    link- https://leetcode.com/problems/minimum-size-subarray-sum/description/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1- binary search
*/

class Solution {
public:

    bool check(vector<int>&nums, int len,int target){
        long long sum=0;int n= nums.size();
        for(int i=0;i<len;i++){
            sum+= nums[i];
        }
        int i=0,j= len-1;
        while(1){
            if(sum>= target) return true;
            if(j+1 <n ) sum = sum- nums[i]+nums[j+1];
            else{
                break;
            }
            i++;j++;
        }
        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int l= 1,r= nums.size();

        while(l<r){
            int mid = l+ (r-l)/2;
            if(check(nums,mid,target)){
                r= mid;
            }
            else{
                l= mid+1;
            }
        }
        if(check(nums,l,target)) return l;
        else return 0;
    }
};