/*
    name= maximum sum rectangle
    link- https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1
    author- Parth garg
    time complexity- o(R*R*C)
    space complexity- o(R)
    method 1- extended kadane's algorithm ;
*/

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        
        
        int mx=INT_MIN;
        for(int i=0;i<R;i++){
            vector<int>dp(C,0);
            for(int j= i;j<R;j++){
                for(int k=0;k<C;k++){
                    dp[k]+= M[j][k];
                }
                int sum=0;
                int maxSum=INT_MIN;
                for(int k=0;k<C;k++){
                    sum+= dp[k];
                    if(sum > maxSum) maxSum= sum;
                    if(sum<0)sum=0;
                }
                mx= max(mx,maxSum);
            }
        }
        return mx;
        
    }
};