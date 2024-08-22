/*
    name= Maximum sum increasing subsequence
    link- https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
    author- Parth garg
    time complexity- O(N^2)
    space complexity- O(N)
    method 2;
*/

class Solution{
	public:
	
	
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>dp(n);
	    for(int i=0;i<n;i++)dp[i]= arr[i];
	    int maxAns= dp[0];
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i] > arr[j] && dp[i] < dp[j]+arr[i]){
	                dp[i]= dp[j]+arr[i];
	            }
	        }
	        if(dp[i] > maxAns) maxAns= dp[i];
	    }
	    
	    return maxAns;
	}  
};