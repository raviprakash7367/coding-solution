/*
    name= maximum sum circular subarray 
    link-https://leetcode.com/problems/maximum-sum-circular-subarray/
    author- Parth garg
    time complexity- o(4n)
    space complexity- o(2n)
    method 1;
*/


class Solution {
public:
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n= nums.size();
        // max1 stores maximum value without using array as circular
        int max1= nums[0];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= nums[i];
            max1= max(max1,sum);
            if(sum<0 ) sum=0;
        }
        
        //finding maximum when using array as circular
        int max2=INT_MIN;
        int maxFront[n],maxBack[n];
        int sum1=nums[0],sum2=nums[n-1];
        maxFront[0]= nums[0];
        maxBack[n-1]= nums[n-1];
        
        for(int i=1;i<n;i++)
        {
            sum1+= nums[i];
            if(sum1>maxFront[i-1])
                maxFront[i]= sum1;
            else
                maxFront[i]= maxFront[i-1];  
        }
        for(int i=n-2;i>=0;i--)
        {
            sum2+= nums[i];
            if(sum2>maxBack[i+1])
                maxBack[i]= sum2;
            else
                maxBack[i]= maxBack[i+1];  
        }
        for(int i=0;i<n-1;i++)
        {
            max2= max(max2, maxFront[i]+maxBack[i+1]);
        }
        
        return max(max1,max2);
        
    }
};