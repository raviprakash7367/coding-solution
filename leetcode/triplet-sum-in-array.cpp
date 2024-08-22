/*
    name= Triplet Sum in Array
    link- https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
    author- Parth garg
    time complexity- O(n2)
    space complexity- O(n)
    method 1- fix one and check for pair using set;
    we can also do this in o(1) space , sort the array,fix one and linearly search for the pair using 2 pointers from left and right
*/




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    bool find3Numbers(int A[], int n, int X)
    {
        for(int i=0;i<n-2;i++)
        {
            unordered_set<int>s;
            int sumAfterFixing= X-A[i];
            for(int j= i+1;j<n;j++)
            {
                if(s.count(sumAfterFixing-A[j])!=0 )
                {
                    return true;
                }
                s.insert(A[j]);
            }
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends