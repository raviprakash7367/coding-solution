/*
    name= Subset Sums
    link- https://practice.geeksforgeeks.org/problems/subset-sums2234/1
    author- Parth garg
    time complexity-  O(2^N)
    space complexity- O(2^N)
    method 1;
*/



//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int>result;
    void subsets(vector<int>&arr, int i,int sum)
    {
        if(i== arr.size())
        {
            result.push_back(sum);
            return ;
        }
        
        subsets(arr, i+1, sum+arr[i]);
        subsets(arr, i+1, sum);  
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        subsets(arr,0,0);
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends