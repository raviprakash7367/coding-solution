/* 
    name= 3Sum
    link- https://leetcode.com/problems/3sum/
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(3n)
    method 1;
*/



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        int n= nums.size();
        for(int i=0;i<= n-3;i++)
        {
            if(i>0 && nums[i]== nums[i-1]) continue;
            if(nums[i]>0) break;
            int target= 0-nums[i];
            int l= i+1;
            int r= n-1;
            
            while(l<r)
            {
                if(nums[l]+nums[r] == target )
                {
                    if(l>i+1 && r<n-1 && nums[l]== nums[l-1] && nums[r]== nums[r+1]) 
                    {
                        l++;
                        r--;
                        continue;
                    }
                    vector<int>v(3);
                    v[0]= nums[i];
                    v[1]= nums[l];
                    v[2]= nums[r];
                    
                    result.push_back(v);
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r] > target ) r--;
                else if(nums[l]+nums[r] < target ) l++;
                
            } 
        }
        return result;   
    }
};