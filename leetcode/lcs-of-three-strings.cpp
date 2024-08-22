/*
    name= lcs-of-three-strings
    link- https://practice.geeksforgeeks.org/problems/lcs-of-three-strings0028/1
    author- Parth garg
    time complexity- O(n1*n2*n3).
    space complexity- O(n1*n2*n3).
    method 1;
*/

int lcs(string &A,string &B, string &C, int i, int j, int k,vector<vector<vector<int>>>&dp){
    if(i==0 || j==0 || k==0)return 0;
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    if(A[i-1]== B[j-1] && A[i-1]== C[k-1]){
        return dp[i][j][k]= 1+ lcs(A,B,C,i-1,j-1,k-1,dp);
    }
    else{
       
        int a1= lcs(A,B,C,i,j,k-1,dp);
        int a2= max(lcs(A,B,C,i,j-1,k,dp), lcs(A,B,C,i-1,j,k,dp));
        return dp[i][j][k]= max(a1, a2);
    }
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    vector<vector<vector<int>>>dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1,-1)));
    return lcs(A,B,C,n1,n2,n3,dp);
}