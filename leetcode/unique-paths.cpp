/*
    name= unique paths
    link- https://leetcode.com/problems/unique-paths/
    author- Parth garg
    time complexity- o(m*n)
    space complexity- o(m*n)
    method 1- ans of every subproblem (i,j) is the sum of ans of subproblems(i+1,j) & (i,j+1);
*/

class Solution {
public:
    int dp[101][101];
    int func(int i, int j,int m,int n)
    {
        if(i>=m-1 || j>= n-1) return 1;

        if(dp[i][j]!= -1) return dp[i][j];
        else return dp[i][j]= func(i+1,j,m,n)+ func(i,j+1,m,n);
    }
    
    int uniquePaths(int m, int n) {
        // dp[i][j] represents the total number of paths for reaching cooridinates m-1,n-1
        
        for(int i=0;i<m-1;i++)
            for(int j=0; j<n-1;j++)
            dp[i][j]= -1;
        
        return func(0,0,m,n);  
    }
};