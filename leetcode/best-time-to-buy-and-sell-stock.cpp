/*
    name= Best time to buy and sell stock
    link- https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    author- Parth garg
    time complexity- o(n)
    method 1 - take he variable which stores the least value arrived upto that index and stores the maximum profit;
*/

class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int maxProf= 0;
        int least= INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]< least) 
                least= prices[i];
            if(prices[i]- least > maxProf) 
                maxProf= prices[i]- least;
        }
        return maxProf;
    }
};