/*
    name= maximum length of pair chain 
    link- https://leetcode.com/problems/maximum-length-of-pair-chain/description/
    author- Parth garg
    time complexity- o(nlogn + n*n) = o(n*n)
    space complexity- o(n*n)
    method 1- dp;
*/

class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0]!= b[0]) return a[0]<b[0];
        else return a[1]<=b[1];
    }

    int solve(vector<vector<int>>&dp, int i,int j ,vector<vector<int>>& pairs){
        if(i == pairs.size()) return 0;
        if(j==-1){
            return max((1+solve(dp,i+1,i,pairs)), solve(dp,i+1,-1,pairs));
        }
        if(dp[i][j]!= -1) return dp[i][j];

        
        else{
            if(pairs[i][0] > pairs[j][1]){
                return dp[i][j] = max((1+solve(dp,i+1,i,pairs)), solve(dp,i+1,j,pairs));
            }
            else{
                return dp[i][j] = solve(dp,i+1,j,pairs);
            }
        }

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n= pairs.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        return solve(dp,0,-1,pairs);
    }
};