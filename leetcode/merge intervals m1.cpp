
/*
    name= merge intervals
    link-https://leetcode.com/problems/merge-intervals/
    author- Parth garg
    time complexity-> o(nlogn)
    method 1- sort vector of vector array then check for intervals if they are intersecting or not
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        if(intervals.size()<=1) return intervals;
        else result.push_back(intervals[0]);
        
        int j=0;
        for(int i=1; i<intervals.size();i++)
        {
            if(intervals[i][0]<= result[j][1]) result [j][1]= max(result [j][1],intervals[i][1]);
            else 
            {
                j++;
                result.push_back(intervals[i]);
            }
        }
        return result;
        
    }
};