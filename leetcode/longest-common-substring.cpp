/*
    name= longest common substring
    link- https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1;
*/

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        memset(dp,-1,sizeof(dp));
        int ans= 0;
        if(n==0 || m==0) return 0;
        for(int i = 0; i<n; i++) dp[i][0] = 0;
        for(int i = 0; i<m; i++) dp[0][i] = 0;
        
        for(int i = 1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(S1[i-1] == S2[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
        
    }
};