/*
    name= friends pairing problem
    link- https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- dp; 
*/

//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    const int m= 1e9+7;
    int countFriendsPairings(int n) 
    { 
        int prev1= 1;
        int prev2= 0;
        int ans;
        for(int i= 1;i<=n;i++){
            ans= ((prev1%m) + ((prev2*(1LL)*(i-1))%m))%m;
            prev2= prev1;
            prev1= ans;
        }
        
        return ans;
        
        
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends