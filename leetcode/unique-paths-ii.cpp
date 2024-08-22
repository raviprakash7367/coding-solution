/*
    name= unique paths ii
    link- https://leetcode.com/problems/unique-paths-ii/
    author- Parth garg
    time complexity- o(m*n)
    space complexity- o(m*n)
    method 1- firstly marks all the coordinates in dp array as 0 which contains obstacles;
*/

class Solution {
public:
    
    int dp[101][101];
    int func(int i, int j,int m,int n)
    {
        if(i== m-1 && j== n-1) return (dp[i][j]== 0) ? 0 : 1;
        if(dp[i][j]!= -1) return dp[i][j];
        if(i== m-1) return dp[i][j]= func(i,j+1,m,n);
        else if(j== n-1) return dp[i][j]= func(i+1,j,m,n);
               
        return dp[i][j]= func(i+1,j,m,n)+ func(i,j+1,m,n);

    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m,n;
        m= obstacleGrid.size();
        n= obstacleGrid[0].size();

        for(int i=0;i<=m-1;i++)
            for(int j=0; j<=n-1;j++)
            dp[i][j]= -1;
        
        
        for(int i=0; i<m;i++)
        for(int j=0; j<n;j++)
        {
            if(obstacleGrid[i][j]== 1) 
            {
                dp[i][j]=0;
            }
        }
        
        return func(0,0, m,n);
        
    }
};