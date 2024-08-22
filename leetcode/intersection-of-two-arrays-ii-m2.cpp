
/*
    name- intersection-of-two-arrays-ii
    link- https://leetcode.com/problems/intersection-of-two-arrays-ii/
    author- Parth garg
    time complexity- o(n);
    method 2- use unordered map for saving the freq of numbers in first array
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        vector<int>result;
        for(int i=0;i<nums1.size();i++)
            freq[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
        {
            if(freq[nums2[i]])
            {
                result.push_back(nums2[i]);
                freq[nums2[i]]--;
            }
        }
        return result;
        
    }
};