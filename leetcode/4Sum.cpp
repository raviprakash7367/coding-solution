/*
    name= 4 sum
    link- https://leetcode.com/problems/4sum/
    author- Parth garg
    time complexity- o(n^3)
    space complexity- o(4*n)
    method 1- use the nested for loops and use break and continue statements for avoiding repeated quadruplets;
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        if(n<4) return {}; 
        sort(nums.begin(),nums.end());

        vector<vector<int>>result;
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]== nums[i-1])continue;
            long long minSum= (long long)nums[i]+(long long)nums[i+1]+(long long)nums[i+2]+(long long)nums[i+3];
            long long maxSum= (long long)nums[i]+(long long)nums[n-3]+(long long)nums[n-2]+(long long)nums[n-1];
            if(minSum >target) break;
            if(maxSum<target)continue;
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]== nums[j-1])continue;
                long long minSum1= (long long)nums[i]+(long long)nums[j]+(long long)nums[j+1]+(long long)nums[j+2];
                long long maxSum1= (long long)nums[i]+(long long)nums[j]+(long long)nums[n-2]+(long long)nums[n-1];
                if(minSum1 >target) break;
                if(maxSum1 <target)continue;
                    
                int l= j+1,r=n-1;
                
                while(l<r)
                {
                    long long sum= (long long)nums[i]+(long long)nums[j]+(long long)nums[l]+(long long)nums[r];
                    if(sum== target)
                    {
                        result.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l<r && nums[l]== nums[l-1])l++;
                        while(l<r && nums[r]== nums[r+1])r--;
                    }
                    else if(sum>target)
                    {
                        r--;
                    }
                    else
                    {
                        l++;
                    }                     
                }
            }
        }
        
        return result;
        
    }
};