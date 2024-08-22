/*
    name= longest repeating-subsequence
    link- https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1;
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    
	    int LRS(vector<vector<int>>&dp, int i ,int j, string &s){
	        if(i>=s.length() || j>=s.length()) return 0;
	        if(dp[i][j]!= -1) return dp[i][j];
	        if(s[i] == s[j] && i!= j){
	            return dp[i][j]= 1+ LRS(dp, i+1,j+1, s);
	        }
	        else return dp[i][j]= max(LRS(dp,i+1,j,s), LRS(dp,i,j+1,s));
	    }
	    
		int LongestRepeatingSubsequence(string str){
		    int n= str.size();
		    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
		    
		    return LRS(dp,0,0,str);
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends