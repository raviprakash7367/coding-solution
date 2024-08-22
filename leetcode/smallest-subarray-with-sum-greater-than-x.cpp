/*
    name= Smallest subarray with sum greater than x
    link- https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        if(n==1)
        {
            if(arr[0]>x) return 1;
            else return 0;
        }
        
        int l=0,r=0;
        int ans= INT_MAX;
        int sum=0;
        while(r<n)
        {
            sum+= arr[r];
            while(sum>x && l<=r)
            {
                ans= min(ans,r-l+1);
                sum-= arr[l];
                l++;
            }
            r++;
            
        }
        return ans;
          
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends