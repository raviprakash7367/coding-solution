/*
    name= Painting the Fence
    link- https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- dp ;
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    const int m= 1e9+7;
    
    long long findWays(int i, int k ,int n, vector<long long>&dp){
        if(i==n) return 1;
        else if(i>n) return 0;
        
        if(dp[i]!= -1) return dp[i];
        
        dp[i]= ((k-1)*(1LL)*(findWays(i+1,k,n,dp)%m+ findWays(i+2,k,n,dp)%m))%m;
        return dp[i];
    }
    
    long long countWays(int n, int k){
        if(k==1 && n>2) return 0;
        vector<long long>dp(n,-1);
        long long ans= (k*((findWays(1,k,n,dp) +findWays(2,k,n,dp))%m))%m; 
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends