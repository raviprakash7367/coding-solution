/*
    name= assign cookies
    link-https://leetcode.com/problems/assign-cookies/
    author- Parth garg
    time complexity-> o(nlogn)
    method 1- sort both arrays then check from begining in both the arrays
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0,i=0;
        int count=0;
        while(i<s.size() && j< g.size())
        {
            if(s[i]>= g[j])
            {
                j++;
                count++;
            }
            i++;
        }
        return count;
    }
};