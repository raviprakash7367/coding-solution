/*
    name= maximum length of subarray with positive product 
    link- https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- every time when a 0 arrives solve for new interval, reset the value of everthing and take the maximum of all intervals;
*/



class Solution {
public:
   
    int getMaxLen(vector<int>& nums) {
        int n= nums.size();
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            int j,neg=0,pos=0,firstNeg=-1,lastNeg;
            for(j= i;j<n;j++)
            {
                if(nums[j]<0) 
                {
                    neg++;
                    lastNeg= j;
                }
                if(nums[j]>0) pos++;
                if(nums[j]==0) break;
                
                if(nums[j]<0 && firstNeg==-1) firstNeg= j;
                
            }
            if(neg%2==0) 
               maxLen= max(maxLen, neg+pos);
            else
            {
                maxLen= max(maxLen, neg+pos- firstNeg+(i-1));
                maxLen= max(maxLen, lastNeg-i);
            }
            
            i=j;
        }
        return maxLen;
    }
};