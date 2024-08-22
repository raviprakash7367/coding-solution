/*
    name= inteleaved strings
    link- https://practice.geeksforgeeks.org/problems/interleaved-strings/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1;
*/

class Solution{
  public:
    
    int solve(vector<vector<int>>&dp, int i, int j, int k, string &A, string &B, string &C){
        if(k == C.length()) return 1;

        if(dp[i][j]!= -1) return dp[i][j];
        int a=0, b= 0;
        if(i<A.length() && A[i] == C[k]){
            a=  solve(dp, i+1,j,k+1, A,B,C);
        }
        if(j<B.length() && B[j] == C[k]){
            b= solve(dp, i,j+1,k+1, A,B,C);
        }
        return dp[i][j] = (a ||b);
    }
    
    bool isInterleave(string A, string B, string C) 
    {
        int n= A.length();
        int m= B.length();
        if(n+m != C.length());
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(dp,0,0,0,A,B,C);
    }

};