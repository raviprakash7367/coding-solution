/* 
    name= longest increasing subsequence
    link- https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
    author- Parth garg
    time complexity- o(nlogn )
    space complexity- o(n)
    method 1- dp + binary search;
            - time and space complexity will be o(n*n) if we use only dp 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    
    int solve(int n, int a[]){
        if(n==0) return 0;
        vector<int>v;
        v.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]> v.back()){
                v.push_back(a[i]);
            }
            else{
                int idx= lower_bound(v.begin(),v.end(),a[i]) - v.begin();
                v[idx]= a[i];
            }
        }
        
        return v.size();
    }
    
    int longestSubsequence(int n, int a[])
    {
        return solve(n,a);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends