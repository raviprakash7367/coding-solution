/*
    name= house robber 
    link- https://leetcode.com/problems/house-robber/
    author- Parth garg
    time complexity- o(n)
    method 1- DP/ recursion;
*/

class Solution {
public:
    
    int dparr[101];
    int dp(vector<int> &nums, int n)
    {
        if(n==0) return nums[0];
        else if(n==1) return max(nums[0],nums[1]);
        
        if(dparr[n-1] == -1 && dparr[n-2]== -1)
        dparr[n] = max(dp(nums,n-1) , dp(nums,n-2)+ nums[n]);
        
        else if(dparr[n-1] != -1 && dparr[n-2]== -1)
        dparr[n] = max(dparr[n-1] , dp(nums,n-2)+ nums[n]);  
        
        else if(dparr[n-1] == -1 && dparr[n-2] != -1)
        dparr[n] = max(dp(nums,n-1) , dparr[n-2]+ nums[n]);  
        
        else 
        dparr[n] = max(dparr[n-1] , dparr[n-2]+ nums[n]);
        
        return dparr[n];
    }
    
    int rob(vector<int>& nums) {
    for(int i=0;i<101;i++) dparr[i]= -1;
        return dp(nums,nums.size()-1);
        
    }
};