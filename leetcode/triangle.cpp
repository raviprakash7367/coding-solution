/*
    name= triangle
    link- https://leetcode.com/problems/triangle/
    author- Parth garg
    time complexity-o(n*n)
    space complexity- o(n*n)
    method 1;
*/


class Solution {
public:
    int dp[201][201];
    int findMin(vector<vector<int>>& triangle, int i, int j)
    {
        if(i== triangle.size()) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        
        int sum= triangle[i][j];
        return dp[i][j]= sum + min(findMin(triangle,i+1,j),findMin(triangle,i+1,j+1));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
        
        return findMin(triangle,0,0);
        
    }
};