/*
    name= Minimum Platforms
    link- https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
    author- Parth garg
    time complexity- o(n )
    space complexity- o(n)
    method 1;
*/




//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    
    
    {
        vector<int> arrr(2500, 0);
        
        for(int i=0;i<n;i++){
            arrr[arr[i]]++;
            arrr[dep[i]+1]--;
        }
        
        int sum = 0;
        int ans = 0;
        
        for(int i=0;i<2500;i++){
            sum += arrr[i];
            ans = max(ans,sum);
        }
        
        return ans;
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
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends