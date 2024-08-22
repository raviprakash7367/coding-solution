/*
    name= Longest common subsequence (space optimised)
    link- https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n)
    method 1;
*/

class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        int m= s1.length();
        int n= s2.length();
        int dp[n+1]= {0};
        for(int i=1 ;i<=m;i++){
            int prev=0;
            int curr;
            for(int j=1;j<=n;j++){
                curr = dp[j];
                if(s1[i-1] == s2[j-1]){
                    dp[j]= 1+ prev;
                }
                else {
                    dp[j]= max(dp[j-1], dp[j]);
                }
                prev= curr;
            }
        }
        return dp[n];
    }
};
