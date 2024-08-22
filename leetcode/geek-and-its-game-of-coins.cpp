/*
    name= geek and its game of coins
    link- https://practice.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

class Solution{

	public:
	
	int x,y;
	int check(vector<int>&dp, int i){
	    
	    if(i == 1 || i== x|| i==y) return 1;
	    
	    if(dp[i]!= -1) return dp[i];
	    
	    int a= (i>=x)? check(dp,i-x): 1;
	    int b= (i>=y)? check(dp,i-y): 1;
	    int c= (i>=1)? check(dp,i-1): 1;
	    
	   return dp[i]= (!a || !b || !c);
	}
	
	int findWinner(int N, int X, int Y)
	{
	    vector<int>dp(N+1,-1);
	    x= X;
	    y= Y;
        return check(dp,N);
	}

};