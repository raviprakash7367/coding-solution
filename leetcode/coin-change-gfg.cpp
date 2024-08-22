/*
    name= coin change
    link- https://practice.geeksforgeeks.org/problems/coin-change2448/1
    author- Parth garg
    time complexity- o(size * n)
    space complexity- o(size*n)
    method 1;
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    long long findCount(int coins[], int n, int w, int i, int j,vector<vector<long long>>&dp){
        if(j== 0) {
            return 1;
        }
        else if(i==0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(coins[i-1]<= j){
            long long a= findCount(coins, n, w, i,j-coins[i-1],dp);
            long long b= findCount(coins, n, w, i-1,j,dp);
            return dp[i][j] = a+b;
        }
        else{
            long long b= findCount(coins,n,w,i-1,j,dp);
            return dp[i][j] = b;
        }
    }
  
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long>>dp(N+1, vector<long long>(sum+1));
        for(int i=0;i<N+1; i++){
            for(int j=0;j<sum+1;j++){
                dp[i][j]= -1;
            }
        }
        for(int i=0;i<sum+1;i++)dp[0][i]= 0;
        for(int i=0;i<N+1; i++) dp[i][0]= 1;
        
        long long res = findCount(coins,N,sum,N,sum,dp);
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends