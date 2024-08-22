/*
    name= Trapping rain water
    link- https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/




//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int l=0,r=n-1;
        int lMax= arr[0],rMax=arr[n-1];
        long long ans=0;
        while(l<=r)
        {
            if(lMax<rMax)
            {
                if(arr[l]>lMax)
                {
                    lMax= arr[l];
                }
                ans+= lMax-arr[l];
                l++;
            }
            else
            {
                if(arr[r]>rMax)
                {
                    rMax= arr[r];
                }
                ans+= rMax-arr[r];
                r--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends