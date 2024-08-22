/*
    name= max sum without adjacents 2
    link- https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents-2/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 2 - we have 3 choices 
            (i) not take a[i]
            (ii) take a[i] and not take a[i-1]
            (iii) take a[i] , a[i-1] and not take a[i-2]
            take the maximum of 3 cases 
*/

class Solution{
  public:
  
  int solve(vector<int>&dp, vector<int>&a, int n){
      if(n== -1) return 0;
      if(n== 0) return a[0];
      if(n== 1) return a[0]+ a[1];
      
      if(dp[n]!= -1) return dp[n];
      
      return dp[n]= max(max(solve(dp,a,n-1),a[n]+solve(dp,a,n-2)),a[n]+a[n-1]+solve(dp,a,n-3));
      
  }
  
  int findMaxSum(vector<int>& a){
      int n= a.size();
      vector<int>dp(n,-1);
      int ans= solve(dp,a,n-1);
      return ans;
  }
};