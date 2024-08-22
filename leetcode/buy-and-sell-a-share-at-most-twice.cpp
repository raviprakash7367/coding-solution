/*
    name= buy and sell a share at most twice
    link- https://practice.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1 - if we use 3d dp then o(n) space is used (nX2X3) size
                we need only current and next row in the dp array so optimise this and make 2 arrays of 2x3 size
*/

int solve(vector<int>&price){
    int n= price.size();
    vector<vector<int>>curr(2,vector<int>(3,0));
    vector<vector<int>>next(2,vector<int>(3,0));
    
    for(int i= n-1;i>=0;i--){
        for(int buy = 0; buy <= 1;buy++){
            for(int limit= 1; limit <=2;limit ++){
                int profit = 0;
                if(buy){
                    int buykaro= -price[i] + next[0][limit];
                    int skipkaro= next[1][limit];
                    profit= max(buykaro,skipkaro);
                }
                else{
                    int sellkaro= price[i] + next[1][limit-1];
                    int skipkaro= next[0][limit];
                    profit = max(sellkaro,skipkaro);
                }
                curr[buy][limit]= profit;
            }
        }
        next= curr;
    }
    return next[1][2];
}


int maxProfit(vector<int>&price){
    return solve(price);
    
}