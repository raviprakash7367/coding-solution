/*
    name= 0 - 1 Knapsack Problem
    link- https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
    author- Parth garg
    time complexity- o(n*w)
    space complexity- o(n*w)
    method 1;
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int findSubset(int wt[],int val[], int n,vector<vector<int>>&dp , int i, int j){
        if(i<=0 || j<=0) return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(wt[i-1] <= j){
            return dp[i][j]= max(val[i-1]+findSubset(wt,val,n,dp,i-1,j-wt[i-1]) , findSubset(wt,val,n,dp,i-1,j));
        }
        else 
            return dp[i][j]= findSubset(wt,val,n,dp,i-1,j);
            
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
        return findSubset(wt,val,n,dp,n,W);
        
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends