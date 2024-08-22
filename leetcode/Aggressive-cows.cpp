/*
    name= Aggressive cows
    link- https://www.spoj.com/problems/AGGRCOW/
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1- fix the difference using binary search then count the number of cows;
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)

bool check(vector<int>&arr, int n, int c, int mid)
{
    int s = 0;
    int count=1;
    for(int i=1;i<n;i++)
    {
        int diff = arr[i]-arr[s];
        if(diff >= mid){
            s = i;
            count++;
        }
    }

    if(count>=c)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int largestMinimumDistance(vector<int>&arr,int n, int c)
{
    int low= 0;
    int max= arr[n-1],min= arr[0];
    int high= max-min;

    while(low<high)
    {
        int mid = low + (high-low+1)/2;
        if(check(arr,n,c,mid))
        {
           low = mid;
        }
        else
        {
           high = mid-1;
        }
    }
    return low;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,c;
        cin>>n>>c;
        vector<int>arr(n);
        fori(i,n)cin>>arr[i];
        sort(arr.begin(),arr.end()); 
        cout<< largestMinimumDistance(arr,n,c)<<endl;
    }
}