/*
    name= number of ways to earn points
    link- https://leetcode.com/problems/number-of-ways-to-earn-points/
    author- Parth garg
    time complexity-  o(n*target)
    space complexity- o(n*target)
    method 1;
*/

class Solution {
public:
    const int m= 1e9+7;
    int findcount(vector<vector<int>>&dp, vector<vector<int>>& types, int i, int j){
        if(j==0) return dp[i][j]= 1;
        else if(i==0) return dp[i][j]= 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        long long sum= 0;
        int count= types[i-1][0];
        for(int k= 0; k<= count; k++)
        {
            if( j >= (k* types[i-1][1])){
                sum= (sum + findcount(dp,types,i-1,j- (k*types[i-1][1])))%m;
            }
        }     
        
        return dp[i][j] = sum;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n= types.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        
        int ans= findcount(dp,types,n,target);
        
        return ans;
    }
};