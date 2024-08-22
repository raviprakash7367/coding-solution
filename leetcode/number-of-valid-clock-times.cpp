/*
    name= number of valid clock times
    link- https://leetcode.com/problems/number-of-valid-clock-times/
    author- Parth garg
    time complexity- o(1)
    space complexity- o(1)
    method 1;
*/


class Solution {
public:
    int countTime(string time) {
        int a=1,b=1,c=1,d=1;
        if(time[0]=='?')
        {
            if(time[1]=='?')
            {
               a= 24; 
            }
            else
            {
                a= (time[1]>='4')? 2 : 3;
            }
        }
        else if(time[1]== '?' && time[0]=='2') b= 4;
        else if(time[1]=='?') b= 10;
        
        if(time[3]=='?' && time[4]=='?') c= 60;
        else if(time[3]=='?') c=6;
        else if(time[4]=='?') d=10;
        
        return a*b*c*d;
    }
};