/*
    name= edit distance
    link- https://practice.geeksforgeeks.org/problems/edit-distance3702/1
    author- Parth garg
    time complexity- o(s*t)
    space complexity- o(s*t)
    method 1- dp;
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int findMin(string &s, string &t, vector<vector<int>>&dp, int i, int j)
    {
        if(i== s.length() && j== t.length()){
            return 0;
        }
        else if(i== s.length()){
            return 1+ findMin(s,t,dp,i,j+1);
        }
        else if(j== t.length()){
            return 1+ findMin(s,t,dp,i+1,j);
        }
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(s[i]== t[j]){
            return dp[i][j]= findMin(s,t,dp,i+1,j+1);
        }
        else{
            int replace= 1+ findMin(s,t,dp,i+1,j+1);
            int remov= 1+ findMin(s,t,dp,i+1,j);
            int insert= 1+ findMin(s,t,dp,i,j+1);
            
            return dp[i][j]= min(replace,min(remov,insert));
        }
    }
  
    int editDistance(string s, string t) {
        int n1= s.length(),n2= t.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        
        return findMin(s,t,dp,0,0);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends