/*
    name= minimum cost for tickets
    link- https://leetcode.com/problems/minimum-cost-for-tickets/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- dp;
*/

class Solution {
public:

    int findNextIdx(vector<int>&days, int currIdx, int duration){
        int target= days[currIdx]+ duration -1;
        for(int i= currIdx+1; i< days.size();i++){
            if(days[i] > target)return i;
        }
        return days.size();
    }

    int findMinCost(vector<int>&dp, vector<int>& days, vector<int>& costs,vector<int>&ticketDurations, int j){ 
        if(j>= days.size()) return 0;
        if(dp[j] != -1) return dp[j];
        int ans = INT_MAX;
        
        for(int i=0 ;i<3;i++){
            int nextIdx = findNextIdx(days,j,ticketDurations[i]);
            int travelCost= costs[i] + findMinCost(dp, days,costs,ticketDurations,nextIdx);
            ans= min (ans, travelCost);
        }
        return dp[j]= ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n= days.size();
        vector<int>dp(n,-1);
        vector<int>ticketDurations = {1,7,30};

        return findMinCost(dp,days,costs,ticketDurations,0);
    }
};