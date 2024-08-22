/*
    name= maximum sum circular subarray 
    link-https://leetcode.com/problems/maximum-sum-circular-subarray/
    author- Parth garg
    time complexity- o(2n)
    space complexity- o(1)
    method 1;
*/



class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();
        int totalArraySum=0;
        // max1 stores maximum value without using array as circular
        int max1= nums[0];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            totalArraySum+= nums[i];
            sum+= nums[i];
            max1= max(max1,sum);
            if(sum<0 ) sum=0;
        }
        
        //finding minimum subarray sum
        int max2;
        int sum2=0;
        int min1= INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum2+= nums[i];
            min1= min(min1,sum2);
            if(sum2>0) sum2=0;
        }
        max2= totalArraySum- min1;
        
        return max1>0 ? max(max1,max2) : max1 ;
        
    }
};