/*
    name= K-th element of two sorted Arrays
    link-  https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
    author- Parth garg
    time complexity- o(x* log(m+n)); where x = log(min-max);
    space complexity- o(1)
    method 1- binary search;
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    
    int count(int nums[], int target,int n)
    {
        int l=0,r= n-1;
        while(l<=r)
        {
            int mid= l+ (r-l)/2;
            if(nums[mid]>target)
            {
                r= mid-1;
            }
            else 
            {
                l= mid+1;
            }
        }
        return l;
    }
    
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        int l= min(nums1[0],nums2[0]), r= max(nums1[n-1],nums2[m-1]);
        while(l<=r)
        {
            int mid = (l+r)/2;
            int numberOfElements= count(nums1,mid,n)+ count(nums2,mid,m);
            
            if(numberOfElements >= k)
            {
                r= mid-1;
            }
            else 
            {
                l= mid+1;
            }
        }
        return l;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends