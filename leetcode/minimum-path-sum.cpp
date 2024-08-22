/*
    name= minimum path sum
    link- https://leetcode.com/problems/minimum-path-sum/
    author- Parth garg
    time complexity- o(m*n)
    space complexity- o(m*n)
    method 1- use dp;
*/

class Solution {
public:
    int minSum;
    int dp[201][201];
    int minPath(vector<vector<int>>& grid, int i, int j,int m, int n)
    {
        if(i== m-1 && j== n-1) return grid[i][j];
        else if(i== m-1) return grid[i][j] +minPath(grid,i,j+1,m,n);
        else if(j== n-1) return grid[i][j]+ minPath(grid,i+1,j,m,n);
        
        if(dp[i][j] != -1) return dp[i][j];
        else return dp[i][j] = grid[i][j]+ min(minPath(grid,i+1,j,m,n), minPath(grid,i,j+1,m,n));
            
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            dp[i][j]= -1;
        
        return minPath(grid,0,0,m,n);
        
    }
};