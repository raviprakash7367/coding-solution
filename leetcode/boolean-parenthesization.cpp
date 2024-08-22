/*
    name= boolean parenthesization
    link- https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1
    author- Parth garg
    time complexity- o(n*n*n)
    space complexity- o(n*n*2) ~ o(n*n)
    method 1- MCM , 3d dp; 
*/

class Solution{
public:
    
    int solve(vector<vector<vector<int>>>&dp , string &s, int i, int j, bool istrue){
        if(i>j) return 0;
        if(i==j){
            if(istrue) return s[i]=='T';
            else return s[i]== 'F';
        }
        if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
        int ans= 0;
        for(int k=i+1;k<j;k+=2){
            int lt= solve(dp,s,i,k-1,true);
            int lf= solve(dp,s,i,k-1,false);
            int rt= solve(dp,s,k+1,j,true);
            int rf= solve(dp,s,k+1,j,false);
            
            if(s[k]== '|'){
                if(istrue){
                    ans+= ((lt*rt)+(lt*rf)+(lf*rt));
                }
                else{
                    ans+= (lf*rf);
                }
            }
            else if(s[k]== '&'){
                if(istrue){
                    ans+= (lt*rt);
                }
                else{
                    ans+= ((lt*rf)+(lf*rt)+(lf*rf));
                }
            }
            else if(s[k]== '^'){
                if(istrue){
                    ans+= ((lt*rf)+(lf*rt));
                }
                else{
                    ans+= ((lt*rt)+(lf*rf));
                }
            }
            
        }
        return dp[i][j][istrue]= ans% 1003;
    }

    int countWays(int N, string S){
        vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(N+1,vector<int>(2,-1)));
        return solve(dp,S,0,N-1,true);
    }
};