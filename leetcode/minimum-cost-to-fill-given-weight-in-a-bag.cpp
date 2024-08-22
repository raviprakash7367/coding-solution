/*
    name= minimum cost to fill given weight in a bag
    link- https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1;
*/

class Solution{
	public:
	
	int solve(vector<vector<int>>&dp, int cost[], int i, int j){
	    if(j==0) return 0;
	    if(i==0) return (1e8);
	    
	    if(dp[i][j]!= -2)return dp[i][j];
	    if(cost[i-1] != -1 && i <= j){
	        return dp[i][j]= min(cost[i-1]+ solve(dp,cost,i,j-i),  solve(dp,cost,i-1,j));
	    }
	    else{
	        return dp[i][j]= solve(dp,cost,i-1,j);
	    }
	}
	
	int minimumCost(int cost[], int N, int W) 
	{ 
        vector<vector<int>>dp(N+1, vector<int>(W+1,-2));
        int ans= solve(dp,cost,N,W);
        if(ans>= (1e8)) return -1;
        else return ans;
	} 
};