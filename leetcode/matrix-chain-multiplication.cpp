
/*
    name= matrix chain multiplication
    link- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    author- Parth garg
    time complexity- o(n^3)
    space complexity- o(n^2)
    method 1- iterate for k in between i to j and find the minimum ans and store in dp;
*/



class Solution{
public:
    int dp[101][101];
    
    int solve(int arr[],int i, int j)
    {
        if(i>=j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int tempAns= INT_MAX;
        for(int k= i;k<=j-1;k++)
        {
            tempAns= min(tempAns, solve(arr,i,k) + solve(arr,k+1,j)+ (arr[i-1]*arr[k]*arr[j]));
        }
        return dp[i][j]= tempAns;
    }
    
    
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
    }
};