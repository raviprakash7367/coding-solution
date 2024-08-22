/*
    name= counting bits
    link- https://leetcode.com/problems/counting-bits/
    author- Parth garg
    time complexity- o(n)
    method 1- lets suppose is any number takes n bits to be represent
     in binary then all the numbers which takes n bits are made up by
     adding 0/1 at the last of all n-1 bit numbers;
*/

class Solution {
public:
    vector<int> countBits(int n) {       
        vector<int> dp(n+1);
        dp[0]=0;
        if(n>0)
        {
            dp[1]= 1;
            int j= 1;
            for(int i=2;i<=n;i= i+2)
            {
                dp[i]= dp[j];
                if(i+1 <= n) dp[i+1]= dp[j]+1;
                j++;
            }
        }
        return dp;
    }
};