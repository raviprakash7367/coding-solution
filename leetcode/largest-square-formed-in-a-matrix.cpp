/*
    name= largest square formed in a matrix
    link- https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- we can do this in o(n) space if we solve it iteratively we need ans of only 
            current row and previous row which can be stored in o(n) space;
*/

class Solution{
public:
    int solve(vector<vector<int>>&dp, vector<vector<int>>&mat, int i, int j){
        if(j== (mat[0].size()-1) || i== (mat.size()-1)){
            return mat[i][j];
        }
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(mat[i][j]== 0) return dp[i][j]= 0;
        else{
            return dp[i][j] = 1+ min(solve(dp,mat,i,j+1), min(solve(dp,mat,i+1,j),solve(dp,mat,i+1,j+1)));
        }
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        vector<vector<int>>dp(n,vector<int>(m,-1));
        solve(dp,mat,0,0);
        int ans= INT_MIN;
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
                ans= max(ans,solve(dp,mat,i,j));
            }
        }
        return ans;
    }
};