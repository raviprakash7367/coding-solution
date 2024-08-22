
/*
    name= Get maximum in generated array
    link- https://leetcode.com/problems/get-maximum-in-generated-array/
    author- Parth garg
    time complexity- o(n)
    method 1- insert the values in array index wise and check for maximum;
*/

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n<=1) return n;
        int nums[n+1];
        nums[0]=0;nums[1]=1;
        int max=1;
        for(int i=2;i<n+1;i++)
        {
            if(i%2==0)
            {
                nums[i]= nums[i/2];
            }
            else
            {
                nums[i]= nums[i/2]+ nums[(i/2)+1];
            }
            if(nums[i]>max) max= nums[i];
        }
        return max;
    }
};