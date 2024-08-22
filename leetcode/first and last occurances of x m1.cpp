/*
    name- first and last occurance of x
    link- https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1
    author-Parth garg
    time complexity= worst case o(n) , avg case o(logn)
    method 1= using binary search
*/



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> result;
    int l=0,r= n-1;
    int mid;
    while(l<=r)
    {
        mid= (l+r)/2;
        if(arr[mid]==x) break;
        else if(arr[mid]>x) r= mid-1;
        else if(arr[mid]<x) l= mid+1;
        
    }
    if(arr[mid]!= x)
    {
        result.push_back(-1);
        result.push_back(-1);
        return result;
    }
    else 
    {
        int temp1= mid,temp2= mid;
        while(temp1>=0)
        {
            if(arr[temp1]!= x)
            {
                break;
            }
            temp1--;
        }
        if(temp1<0) result.push_back(0);
        else result.push_back(temp1+1);
        
        while(temp2<n)
        {
            if(arr[temp2]!= x)
            {
                break;
            }
            temp2++;
        }
        if(temp2>=n) result.push_back(n-1);
        else result.push_back(temp2-1);
    }
    return result;
    
    
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends