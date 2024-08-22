/*
    name= time needed to buy tickets
    link- https://leetcode.com/problems/time-needed-to-buy-tickets/submissions/
    author- Parth garg
    time complexity- o(nlogn)
    method 1- In left part of array every element comes tickets[k] times of if element is smaller than it comes for the no. of tickets he want times.
    in the right half the elements with ticket value more than tickets[k] comes tickets[k]-1 times because in last pass these will not be counted in the result.
*/

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        
        if(tickets.size()==1) return tickets[0];
       
        int result=0;
        for(int i=0;i<k;i++)
        {
            if(tickets[i]<tickets[k]) result+= tickets[i];
            else result+= tickets[k];
        }
        result+= tickets[k];
        for(int i=k+1;i<tickets.size();i++)
        {
            if(tickets[i]<tickets[k]) result+= tickets[i];
            else result+= tickets[k]-1;
        }
        return result;
        
    }
};