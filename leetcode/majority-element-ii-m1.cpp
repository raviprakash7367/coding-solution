/*
    name= majority element ii
    link- https://leetcode.com/problems/majority-element-ii/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity-o(1)
    method 1- sort the array then count the frequency;
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int count=1;
        vector<int>result;
        float minFreq= n/3;
        for(int i=0;i<=n-2;i++)
        {
            if(nums[i]== nums[i+1]) count++;
            else
            {
                if(count>minFreq) 
                    result.push_back(nums[i]);
                count=1;
            }
        }
        
        if(count>minFreq) 
            result.push_back(nums[n-1]);
        return result;
    }
};