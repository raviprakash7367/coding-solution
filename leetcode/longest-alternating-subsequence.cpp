/*
    name= Longest alternating subsequence
    link- https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution {
	public:
	    
	    
	    
		int AlternatingaMaxLength(vector<int>&nums){
		    int n= nums.size();
		    int mini=1,maxi=1;
		    for(int i=1;i<n;i++){
		        if(nums[i]> nums[i-1]){
		            maxi= mini+1;
		        }
		        else if(nums[i]<nums[i-1]){
		            mini= maxi+1;
		        }
		    }
		    return max(mini,maxi);
		}

};