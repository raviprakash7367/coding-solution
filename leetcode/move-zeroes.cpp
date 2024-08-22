/*
    name- move zeroes
    link-https://leetcode.com/problems/move-zeroes/
    author- parth garg
    time complexity- o(n)  
    method 1- take the count of no. of 0's and remove first and in last push no. of 0's equal to count
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it= nums.begin();
        int n= nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(*it ==0)
            {
                nums.erase(it);
                count++;
            }
             else it++;
        }
        for(int i=0;i<count;i++)
        {
            nums.push_back(0);
        }
        return;
    }
};