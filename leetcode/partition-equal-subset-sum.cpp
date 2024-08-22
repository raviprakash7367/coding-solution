/*
    name= partition equal subset sum
    link- https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
    author- Parth garg
    time complexity- o(n*sum)
    space complexity- o(n*sum)
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
    
    int findSubset(int arr[],int n, vector<vector<int>>&dp, int i, int j){
        if(j==0) return 1;
        else if(i==0) return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(j >= arr[i-1]){
            return dp[i][j]= findSubset(arr,n,dp,i-1,j-arr[i-1]) || findSubset(arr,n,dp,i-1,j);
        }
        else return dp[i][j]= findSubset(arr,n,dp, i-1,j);
    }

    int equalPartition(int N, int arr[])
    {
        int sum =0;
        for(int i=0;i<N;i++){
            sum+= arr[i];
        }
        if(sum%2==1) return 0;
        
        vector<vector<int>>dp(N+1, vector<int>((sum/2)+1,-1));
        return findSubset(arr,N,dp, N,sum/2);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends