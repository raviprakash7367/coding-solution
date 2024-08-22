/*
    name= matrix chain multiplication
    link- https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
    author- Parth garg
    time complexity- o(n^3)
    space complexity- o(n^2)
    method 1;
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int minMultiplications(int arr[], int n, int i, int j, vector<vector<int>>&dp){
        if(i>=j)return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];
        dp[i][j]= INT_MAX;
        for(int k= i;k<j;k++){
            dp[i][j]= min(dp[i][j], (minMultiplications(arr,n,i,k,dp)+minMultiplications(arr,n,k+1,j,dp)+ (arr[i-1]*arr[k]*arr[j])));
        }
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return minMultiplications(arr,N,1,N-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends