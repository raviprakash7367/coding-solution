/*  
    name - teemo attacking
    link-https://leetcode.com/problems/teemo-attacking/
    author- Parth garg
    time complexity- o(n)
    method 1;
*/

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int sum=0;
        if(timeSeries.size()==1) return duration;
        for(int i=0;i<timeSeries.size()-1;i++)
        {
            if(timeSeries[i]+duration-1 >= timeSeries[i+1])
            {
                sum+= timeSeries[i+1]-timeSeries[i];
            }
            else
            {
                sum+= duration;
            }
        }
        sum+= duration;
        return sum;
    }
};