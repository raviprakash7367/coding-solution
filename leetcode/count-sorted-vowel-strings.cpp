/*
    name= count sorted vowel strings
    link- https://leetcode.com/problems/count-sorted-vowel-strings/
    author- Parth garg
    time complexity- o(5*n)
    method 1- use dynamic programming;
*/

class Solution {
public:
    
    int countVowelStrings(int n) {
        int dp[n][5];
        for(int i=0;i<5;i++)
        {
            dp[0][i]= 1;
        }
        for(int i=1;i<n;i++)
        {
            dp[i][4]=1;
            for(int j= 3;j>=0;j--)
            {
                dp[i][j]= dp[i][j+1] + dp[i-1][j];
            }
        }
        int ans=0;
        for(int i=0;i<5;i++)
        {
            ans+= dp[n-1][i];
        }
        return ans;
        
    }
};