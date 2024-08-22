/*
    name= binomial coefficient // nCr
    link- https://practice.geeksforgeeks.org/problems/ncr1019/1
    author- Parth garg
    time complexity- o(n*r)
    space complexity- o(r)
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
    const int m= 1e9+7;
    int nCr(int n, int r){
        if(n<r) return 0;
        vector<int>dp(r+1,0);
        if(n-r < r) r= n-r;
        
        for(int i=0;i<=n;i++){
            for(int j=r; j>0;j--){
                dp[j]= (dp[j]+dp[j-1])%m;
            }
            dp[0]= 1;
        }
        return dp[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends