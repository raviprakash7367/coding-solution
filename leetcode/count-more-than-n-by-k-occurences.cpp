/*
    name= Count More than n/k Occurences
    link- https://practice.geeksforgeeks.org/problems/count-element-occurences/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- hash map;
*/


//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int>m;
        float t= n/k;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        for (auto it = m.begin(); it!= m.end();it++)
        {
            if(it->second > t) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t, k;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends