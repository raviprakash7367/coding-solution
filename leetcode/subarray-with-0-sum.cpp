/*
    name= subarray with 0 sum
    link- https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(2*n) 
    method 1;
*/


//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
 
    bool subArrayExists(int arr[], int n)
    {
        vector<int>prefixSum(n,0);
        unordered_map<int,int>freq;
        prefixSum[0]= arr[0];
        freq[prefixSum[0]]++;
        if(arr[0]==0) return true;
        for(int i=1;i<n;i++)
        {
            prefixSum[i]= prefixSum[i-1]+ arr[i];
            if(prefixSum[i]==0) return true;
            freq[prefixSum[i]]++;
            if(freq[prefixSum[i]]==2) 
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends