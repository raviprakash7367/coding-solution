/*
    name= array removal
    link- https://practice.geeksforgeeks.org/problems/array-removals/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1- dp;
*/

class Solution{
    public:
    
    int solve(vector<vector<int>>&dp, vector<int>&arr, int l, int r, int k){
        if(l>=r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        if(arr[r]- arr[l] > k){
            dp[l][r]= 1+ min(solve(dp,arr,l+1,r,k), solve(dp,arr,l,r-1,k));
        }
        else{
            dp[l][r]= 0;
        }
        return dp[l][r];
        
    }
    
    int removals(vector<int>& arr, int k){
        int n= arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        sort(arr.begin(),arr.end());
        int ans= solve(dp,arr,0,n-1,k);
        return ans;
    }
};