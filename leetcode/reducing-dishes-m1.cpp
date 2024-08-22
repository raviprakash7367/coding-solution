/*
    name=  reducing dishes
    link-  https://leetcode.com/problems/reducing-dishes/description/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n*n)
    method 1 - dp;
*/

class Solution {
public:

    int findMaxValue(vector<vector<int>>&dp, vector<int>&satisfaction , int i, int j){
        if(i>= satisfaction.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int take = (satisfaction[i]*(j+1)) + findMaxValue(dp,satisfaction,i+1,j+1);
        int notTake= findMaxValue(dp, satisfaction,i+1,j);
        return dp[i][j]= max(take, notTake);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        int n= satisfaction.size();
        vector<vector<int>>dp (n, vector<int>(n,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return findMaxValue(dp, satisfaction, 0,0);
    }
};