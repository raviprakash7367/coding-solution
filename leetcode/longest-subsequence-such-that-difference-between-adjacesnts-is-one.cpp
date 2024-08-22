/*
    name= longest-subsequence-such-that-difference-between-adjacents-is-one
    link- https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n)
    method 1;
*/

class Solution{
public:
    
    int longestSubsequence(int N, int A[])
    {
        vector<int>dp(N,1);
        int maxAns= 1;
        for(int i=1;i<N;i++){
            for(int j=0;j<i;j++){
                if(abs(A[j]-A[i])==1){
                    dp[i]= max(dp[i], 1+dp[j]);
                }
            }
            if(dp[i]>maxAns) maxAns= dp[i];
        }
        
        return maxAns;
    }
};