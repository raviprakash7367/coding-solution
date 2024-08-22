
/*
    name= count pairs with given sum
    link- https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
    author- Parth garg
    time complexity- o(n)
    space complexity-o(n)
    method 1- store the frequency of elements in map;
*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[arr[i]]++;
        int count= 0;
        
        for(auto it = m.begin(); it!= m.end();it++)
        {
            int key= it->first;
            int value = it->second;
            if(m.count(k-key) != 0)
            {
                if(k== 2* key) 
                    count+= (value*(value -1));
                else if(it->first <= k)
                {
                    count+= (value *(m[k-key]));
                }
            }
        }
        return count/2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends