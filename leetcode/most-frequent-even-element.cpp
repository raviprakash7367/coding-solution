/*
    name=most frequent even element
    link-https://leetcode.com/problems/most-frequent-even-element/
    author- Parth garg
    time complexity-o(n)
    space complexity-o(n)
    method 1- use hash map only for even values;
*/


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                m[nums[i]]++;
            }
        }
        int mf= INT_MAX;
        int maxFreq=0;
        for(auto it = m.begin();it!= m.end();it++)
        {
            if(it->second >maxFreq )
            {
                mf= it->first;
                maxFreq= it->second;
            }  
            else if(it->second ==maxFreq && it->first < mf)
            {
                mf= it->first;
            }
        }
        return (mf==INT_MAX) ? -1 : mf;
    }
};