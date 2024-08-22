/*
    name= Maximum sum increasing subsequence
    link- https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
    author- Parth garg
    time complexity- O(N^2)
    space complexity- O(N^2)
    method 1;
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int solve(int arr[],int n, vector<vector<int>>&dp,int i ,int prev){
	    if(i>=n) return 0;
	    if(dp[i][prev+1] != -1) return dp[i][prev+1];
	    
	    if(prev== -1 || arr[i] > arr[prev])
	    {
	        return dp[i][prev+1] = max(arr[i]+ solve(arr,n,dp,i+1,i), solve(arr,n,dp,i+1,prev));
	    }
	    else{
	        return dp[i][prev+1] = solve(arr,n,dp,i+1,prev);
	    }
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<vector<int>>dp(n,vector<int>(n,-1));
	    int ans= solve(arr, n,dp ,0, -1);
	    return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends