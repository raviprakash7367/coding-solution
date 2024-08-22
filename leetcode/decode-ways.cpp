/*
    name= decode ways
    link- https://leetcode.com/problems/decode-ways/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        int dp[n+1];
        for(int i=0;i<n;i++) dp[i]=0;
        dp[n]= 1;
        for(int i= n-1;i>=0;i--)
        {
            if(s[i] != '0')
            {
                dp[i] = dp[i+1];
            }
            if(i+1< n && (s[i]=='1' || (s[i]== '2' && s[i+1]<='6')))
                dp[i]+= dp[i+2];
        }
        return dp[0];
    }
};