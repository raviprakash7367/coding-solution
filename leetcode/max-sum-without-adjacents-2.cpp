/*
    name= max sum without adjacents 2
    link- https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents-2/1
    author- Parth garg
    time complexity- o(3n)
    space complexity- o(3n)
    method 1- fill the dp array of n X 3 size;
*/

class Solution{
  public:
  
  int solve(vector<vector<int>>&dp, vector<int>& a, int i, int j){
      if(i== a.size()) return 0;
      if(dp[i][j]!= -1) return dp[i][j];
      
      if(j==2){
          return dp[i][j]= solve(dp,a,i+1,0);
      }
      else{
          return dp[i][j]= max(a[i]+solve(dp,a,i+1,j+1), solve(dp,a,i+1,0));
      }
  }
  
  int findMaxSum(vector<int>& a){
      int n= a.size();
      vector<vector<int>>dp(n+1,vector<int>(3,-1));
      int ans= solve(dp,a,0,0);
      return ans;
  }
};