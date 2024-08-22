/*
    name= best sightseeing pair
    link-  https://leetcode.com/problems/best-sightseeing-pair/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        
        int n= values.size();
        int maxAns= INT_MIN;
        int vPlusi,vMinusi,maxFront[n],maxBack[n];
        maxFront[0]= values[0];
        maxBack[n-1]= values[n-1]- n+1;
        for(int i=1;i<n;i++)
        {
            vPlusi= values[i]+i;
            if(vPlusi>maxFront[i-1]) 
            {
                maxFront[i]= vPlusi;
            }
            else 
                maxFront[i]= maxFront[i-1];
        }
        for(int i= n-2;i>=0;i--)
        {
            vMinusi= values[i]-i;
            if(vMinusi> maxBack[i+1])
                maxBack[i]= vMinusi;
            else maxBack[i]= maxBack[i+1];
        }

        for(int i=0;i<n-1;i++)
        {
            if(maxFront[i]+maxBack[i+1] > maxAns) maxAns= maxFront[i]+maxBack[i+1];
        }
        return maxAns;
    }
};