/*
    name= Array Subset of another array
    link-  https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- hash map;
*/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) ;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];

        for (int i = 0; i < n; i++) {
            cin >> a1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> a2[i];
        }

        cout << isSubset(a1, a2, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int>m1,m2;
    for(int i=0;i<n;i++)m1[a1[i]]++;
    
    if(n<m) return "No";
    else
    {
        for(int i=0;i<m;i++)
        {
            if(m1.count(a2[i])==0 || m1[a2[i]]==0)
            {
                return "No";
            }
            m1[a2[i]]--;
        }
        return "Yes";
    }

    
    
}