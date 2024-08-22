/*
    name= valid triangle number
    link- https://leetcode.com/problems/valid-triangle-number/description/
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(1)
    method 1- binary search;
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count =0;
        int n= nums.size();
       
        for(int i= n-1;i>1;i--){
            int low= 0,high= i-1;
            while(low<high){
                if(nums[low]+nums[high] > nums[i]){
                    count+= (high-low);
                    high--;
                }
                else{
                    low++;
                }
            }
        }
        return count;

    }
};