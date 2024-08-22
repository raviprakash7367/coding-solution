/*
    name= https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
    link- find-the-smallest-divisor-given-a-threshold
    author- Parth garg 
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution {
public:
    bool check(vector<int>&nums, int threshold, int mid){
        int count =0;
        for(auto i : nums){
            count+= (ceil((float)i/mid));
        }
        return count <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int l= 1 ,r=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>r)r= nums[i];
        }
        while(l<r){
            int mid = l+ (r-l)/2;
            if(check(nums,threshold, mid)){
                r= mid;
            }
            else{
                l= mid+1;
            }
        }
        return l;
    }
};