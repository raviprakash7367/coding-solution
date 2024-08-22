/*
    name= Longest Palindromic Substring
    link- https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string1956/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 3- solving diagonally ; 
*/

class Solution{   
public:
    
    
    string longestPalindrome(string S){
        int n= S.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        int st;
        int maxLen= 0;
        // diff =(0,0), (0,1), (0,2), (0,3)..... (0,n-1)
        //traversing diagonally
        for(int diff=0;diff<n;diff++){
            for(int i = 0, j = i+diff; j < n ; i++,j++ ){
                if(i==j)dp[i][j]= 1;
                else if(S[i]== S[j] && diff == 1 ) dp[i][j]= 2;
                else if(S[i]== S[j]){
                    if(dp[i+1][j-1]){
                        dp[i][j]= 2+ dp[i+1][j-1];
                    }
                }
                
                if(dp[i][j] > maxLen){
                    maxLen= dp[i][j];
                    st= i;
                }
                
            }
        }
        return S.substr(st,maxLen);
    }
};