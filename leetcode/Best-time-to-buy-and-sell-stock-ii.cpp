/*
    ques name- best time to buy and sell stocks
    link- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    author- parth garg
    time complexity = o(n)
    space complexity= o(1)
    method 1- buy when we have a local minima and sell when we have a local maxima
*/



class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>prices[i-1])
            {
                profit+= prices[i]-prices[i-1];
            }
        }
        return profit;
        
    }
};