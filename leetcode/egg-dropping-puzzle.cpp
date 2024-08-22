/*
    name= egg dropping puzzle
    link- https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
    author- Parth garg
    time complexity- o(f*f*e)
    space complexity- o(f*e)
    method 1 - Matrix Chain Multiplication ;
*/

class Solution
{
    public:
    
    //e= number of eggs
    //f= number of floors
    int solve(vector<vector<int>>&dp, int e, int f){
        if(f== 0 || f== 1) return f;
        if(e == 1) return f;
        
        if(dp[e][f]!= -1) return dp[e][f];
        int mn= INT_MAX;
        for(int k=1;k<=f;k++){
            int temp = 1+ max(solve(dp, e-1,k-1), solve(dp,e,f-k));
            mn= min(mn, temp);
        }
        return dp[e][f]= mn;
        
    }
    
    int eggDrop(int e, int f) 
    {
        vector<vector<int>>dp(e+1,vector<int>(f+1,-1));
        int ans= solve(dp,e,f);
        return ans;
    }
};