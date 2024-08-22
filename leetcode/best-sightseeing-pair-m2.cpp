/*
    name= best sightseeing pair
    link- https://leetcode.com/problems/best-sightseeing-pair/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/



class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n= values.size();
        int ans=0,imax=0;
        for(int i=0;i<n;i++)
        {
            ans= max(ans,imax+ values[i]-i);
            imax= max(imax, values[i]+i);
        }
        return ans;
    }
};