/*
    name= majority element-ii
    link- https://leetcode.com/problems/majority-element-ii/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- here we can have atmost 2 candidates so use num1,num2,count1,count2 for finding majority element;
*/


class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1,num2=-1,count1=0,count2=0;
        int i=0;
        int n= nums.size();
        vector<int>result;
        while(i<n)
        {
            if(nums[i]==num1)count1++;
            else if(nums[i]==num2)count2++;
            else if(count1==0) 
            {
                num1= nums[i];
                count1++;
            }
            else if(count2==0) 
            {
                num2= nums[i];
                count2++;
            }
            else 
            {
                count1--;
                count2--;
            }
            i++;
        }
        
        count1=0;
        count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1) count1++;
            else if(nums[i]==num2)count2++;
        }
        if(count1> n/3) result.push_back(num1);
        if(count2> n/3) result.push_back(num2);
        
        return result;
        
    }
};