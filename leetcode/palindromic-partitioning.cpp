/*
    name= Palindromic Partitioning
    link- https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
    author- Parth garg
    time complexity- o(n*n*n)
    space complexity- o(n*n)
    method 1- mcm;
*/

//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isPalindrome(string &s, int i, int j){
        if(i==j) return true;
        else{
            while(i<j){
                if(s[i]!= s[j] ) return false;
                i++;j--;
            }
        }
        return true;
    }
    
    
    int solveMCM(int i, int j, string &s,vector<vector<int>>&dp){
        if(i>=j) return 0;
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(isPalindrome(s,i,j)) return 0;
        else{
            int ans= INT_MAX;
            for(int k= i; k<=j-1;k++){
                int temp = solveMCM(i,k,s,dp) + solveMCM(k+1,j,s,dp) +1 ;
                ans= min(ans, temp);
            }
            return dp[i][j] = ans;
        }    
    }

    int palindromicPartition(string str)
    {
        int n= str.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solveMCM(0,n-1,str,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends