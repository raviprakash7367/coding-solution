/*
    name= maximum intersecting lines
    link- https://practice.geeksforgeeks.org/problems/63c232252d445a377e01cd91adfd7d1060580038/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1;
*/
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int>mp;
        for(int i=0;i<N;i++){
            mp[lines[i][0]]++;
            mp[lines[i][1]+1]--;
        }
        int ans=0,prefixSum=0;
        for(auto val :mp){
            prefixSum+= val.second;
            ans= max(ans, prefixSum);
        }
        return ans;
    }
};