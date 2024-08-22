/*
    name= Kadane's algorithm
    link- https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1 - take 2 variables one contain max till now and another contain max end here if max end here is negative then make it 0 

*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long maxEndHere=arr[0];
        long long maxTillNow= arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(maxEndHere>=0) maxEndHere+= arr[i];
            else maxEndHere= arr[i];
            
            if(maxEndHere>maxTillNow) maxTillNow= maxEndHere;
        }
        return maxTillNow;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends