/*
    name= maximum path sum in matrix
    link- https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1;
*/

class Solution{
public:
    
    int findMaxPath(vector<vector<int>>&dp ,vector<vector<int>>& matrix, int i, int j){
        if(i == matrix.size()){
            return 0;
        }
        if(j<0 || j >= matrix[0].size()){
            return 0;
        }
        
        if(dp[i][j]!= -1) return dp[i][j];
        return dp[i][j] = matrix[i][j] + max(findMaxPath(dp,matrix,i+1,j),max(findMaxPath(dp,matrix,i+1,j-1),findMaxPath(dp,matrix,i+1,j+1)));
    }
    
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans= 0;
        for(int i=0;i<matrix[0].size();i++){
            ans= max(ans, findMaxPath(dp,matrix,0,i));
        }
        return ans;
    }
};