
/*
    name- intersection of two arrays
    link-https://leetcode.com/problems/intersection-of-two-arrays/
    author- parth garg
    time complexity- o(n)  
    method 1- hashing
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool hash1[1001]={0}, hash2[1001]={0};
        for(int i=0;i<nums1.size();i++) hash1[nums1[i]]= true;
        for(int i=0;i<nums2.size();i++) hash2[nums2[i]]= true;
        vector<int>result;
        for(int i=0;i<=1000;i++)
        {
            if(hash1[i]==1 && hash2[i]==1) result.push_back(i);
        }
        return result;
    }
};