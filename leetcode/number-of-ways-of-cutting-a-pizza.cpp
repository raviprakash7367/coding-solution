/*
    name= number of ways of cutting a pizza
    link- https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/
    author- Parth garg
    time complexity- o(n*m*k)
    space complexity- o(n*m*k)
    method 1- dp+ prefixsum + MCM;
*/

class Solution {
public:
    const int mod = 1e9+7;
    int numberOfWays(vector<vector<vector<int>>>&dp, vector<vector<int>>&prefix,int i,int j, int k,int n, int m){
        if(prefix[i][j]==0) return 0;
        if(k==0) return 1;

        if(dp[i][j][k]!= -1) return dp[i][j][k];

        int ans=0;
        for(int row=i+1;row<n;row++){
            if(prefix[i][j]- prefix[row][j]>0)
                ans= (ans + numberOfWays(dp,prefix,row,j,k-1,n,m))%mod;
        }
        for(int col= j+1;col<m;col++){
            if(prefix[i][j]- prefix[i][col]>0)
                ans= (ans + numberOfWays(dp,prefix,i,col,k-1,n,m))%mod;
        }
        return dp[i][j][k]= ans;
    }


    int ways(vector<string>& pizza, int k) {
        int n= pizza.size(); //row
        int m= pizza[0].size(); //col
        vector<vector<int>>prefix(n+1, vector<int>(m+1,0));
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m,vector<int>(k,-1)));

        for(int i= n-1;i>=0;i--){
            for(int j= m-1;j>=0;j--){
                prefix[i][j] = prefix[i+1][j] + prefix[i][j+1] - prefix[i+1][j+1] + (pizza[i][j]=='A');
            }
        }

        return numberOfWays(dp,prefix,0,0,k-1,n,m);
    }
};