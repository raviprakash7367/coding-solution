/*
    name= maximum length of pair chain 
    link- https://leetcode.com/problems/maximum-length-of-pair-chain/description/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1- dp;
*/

class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }

    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),comp);

        int count =0;
        int prev= INT_MIN;
        for(auto p : pairs){
            if(p[0]> prev){
                count++;
                prev= p[1];
            }
        }
        return count;
    }
};