/*
    name= longest consecutive subsequence
    link- https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
    author- Parth garg
    time complexity- o(n)
    space complexity-o(n)
    method 1- use hashing;
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int hash[100001];
    int findLongestConseqSubseq(int arr[], int N)
    {
        for(int i=0;i<N;i++)hash[arr[i]]=1;
        int max=1;
        
        for(int i=0;i<100001;i++)
        {
            int ans=0;
            while(hash[i]==1)
            {
                i++;
                ans++;
            }
            if(ans>max) max= ans;
        }
        return max;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends