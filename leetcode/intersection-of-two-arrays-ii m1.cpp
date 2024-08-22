/*
    name- intersection-of-two-arrays-ii
    link- https://leetcode.com/problems/intersection-of-two-arrays-ii/
    author- Parth garg
    time complexity- o(nlogn);
    method 1- first sort both the arrays and then check all the elements one by one and pop accordingly  
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>result;
        while(nums1.size()>0 && nums2.size()>0)
        {
            if(nums1[nums1.size()-1]==nums2[nums2.size()-1])
            {
                result.push_back(nums1[nums1.size()-1]);
                nums1.pop_back();
                nums2.pop_back();
            }
            else if(nums1[nums1.size()-1]>nums2[nums2.size()-1])
            {
                nums1.pop_back();
            }
            else 
            {
                nums2.pop_back();
            }
        }
        return result; 
    }
};