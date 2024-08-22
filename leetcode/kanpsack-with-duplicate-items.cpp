/*
    name= Knapsack with Duplicate Items
    link- https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
    author- Parth garg
    time complexity- O(N*W)
    space complexity- O(W)
    method 1- unbounded knapsack dp;
*/
class Solution{
public:

    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[W+1] = {0};
        for(int i = N-1; i >= 0; i--){
            for(int j = W; j >= 0; j--){
                int notTake = dp[j] ;
                if(j+wt[i] <= W){
                    int take = val[i]+dp[j+wt[i]];
                    dp[j] = max(take,notTake);
                }
                else{
                    dp[j] = notTake; 
                }
            }
        }   
        return dp[0];
    }
};