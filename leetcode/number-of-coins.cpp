/*
    name= number of coins
    link- https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    author- Parth garg
    time complexity- o(v*m)
    space complexity- o(v*m)
    method 1- unbounded knapsack dp;
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
    
    int findMinCoins(int coins[],int i,int w, vector<vector<int>>&dp)
    {
        if(i==0 )
        {
            if(w% coins[i]==0)
            {
                return w/coins[i];
            }
            else
                return INT_MAX-1;
        }
        
        
        if(dp[i][w]!= -1) return dp[i][w];
        
        if(coins[i-1]<= w)
        {
            return dp[i][w]=min(findMinCoins(coins,i,w-coins[i-1],dp)+1,findMinCoins(coins,i-1,w,dp)) ;
        }
        else
        {
            return dp[i][w]= findMinCoins(coins,i-1,w,dp);
        }
        
    }
    
	
	int minCoins(int coins[], int m, int v) 
	{ 
	    vector<vector<int>>dp(m+1,vector<int>(v+1,-1));
	    int ans= findMinCoins(coins, m,v,dp);
	   	return (ans== INT_MAX-1) ? -1 : ans ;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends