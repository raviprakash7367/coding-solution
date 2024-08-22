/*
    name= find the original array of prefix xor
    link- https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n) (for storing result)
    method 1- make a variable which contains the xor or 0th to i-1 th index of resultant array;
*/


class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>arr;
        arr.push_back(pref[0]);
        int prevXor= pref[0];
        for(int i=1;i<pref.size();i++)
        {
            arr.push_back(prevXor^pref[i]);
            prevXor= prevXor^arr[i];
        }
        return arr;
    }
};