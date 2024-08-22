/*
    name= longest palindromic substring
    link- https://leetcode.com/problems/longest-palindromic-substring/description/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1- using dp , take help of Longest common subsequence;
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int len= i-j+1;
                if(len==2 && s[i]==s[j]){
                    dp[j][i]=2;
                }
                else{
                    if(dp[j+1][i-1] != 0 && s[i]== s[j]){
                        dp[j][i]= 2+ dp[j+1][i-1];
                    }
                    else{
                        dp[j][i]=0;
                    }
                }
            }
        }
        int ans=0;
        int x,y;
        for(int i=0;i<n;i++){
            for(int j= i;j<n;j++){
                if(dp[i][j]>ans){
                    ans= dp[i][j];
                    x=i;y=j;
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }

        string res;
        for(int i=x; i<=y;i++){
            res+= s[i];
        }
        return res;

    }
};