/*
    name= word wrap
    link- https://practice.geeksforgeeks.org/problems/word-wrap1646/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1;
*/

class Solution {
public:
    
    int solve(vector<vector<int>>&dp, int i, int j, vector<int>&nums, int k){
        if(dp[i][j] != -1) return dp[i][j];
        
        if(i== nums.size()-1){
            if(j==0){
                return 0;
            }
            else{
                if(k-j-1 >= nums[i]) return dp[i][j] = 0;
                else return dp[i][j] = ((k-j)*(k-j)) + solve(dp,i,0,nums,k); 
            }
        }
        else{
            if(j==0) return dp[i][j] = solve(dp,i+1,j+nums[i], nums,k);
            else{
                if(k-j-1 >= nums[i]){
                    return dp[i][j] = min(solve(dp, i+1, j+1+nums[i],nums,k) , ((k-j)*(k-j))+ solve(dp,i,0,nums,k) );
                }
                else{
                    return dp[i][j] = ((k-j)*(k-j)) + solve(dp,i,0,nums,k);
                }
            }
        }
    }

    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n= nums.size();
        vector<vector<int>>dp(n, vector<int>(k+1,-1));
        return solve(dp,0,0,nums,k);
    } 
};