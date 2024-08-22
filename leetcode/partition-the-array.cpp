/*
    name= partition the array
    link- https://practice.geeksforgeeks.org/problems/84912de770541b2a56bee869cf603fab990fd3e5/1 
    author- Parth garg
    time complexity- o(Nlogn)
    space complexity- o(N)
    method 1- binary search;
*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    
    pair<long long,long long>findMedian(vector<long long>&prefixSum, int start, int end){
        int low= start;
        int high= end-1;
        long long res1,res2;
        long long prev= 0;
        if(start>0) prev= prefixSum[start-1];
        long long mini = LONG_MAX;
        while(low<= high){
            int mid = low+ (high-low)/2;
            long long first= prefixSum[mid]- prev;
            long long second= prefixSum[end-1]- prefixSum[mid];
            if(first > second){
                if(first-second < mini){
                    mini = first-second;
                    res1= second;
                    res2= first;
                }
                high = mid-1;
            }
            else if(first == second){
                return {first,second};
            }
            else{
                if(second- first < mini){
                    mini= second-first;
                    res1= first;
                    res2= second;
                }
                low= mid+1;
            }
            
        }
        
        return {res1,res2};
        
    }

    long long minDifference(int N, vector<int> &A) {
        vector<long long>prefixSum(N);
        prefixSum[0]= A[0];
        for(int i=1;i<N;i++){
            prefixSum[i]= prefixSum[i-1]+ A[i];
        }
        long long ans= LONG_MAX;
        for(int i= 2; i<N-1;i++){
            auto left = findMedian(prefixSum, 0,i);
            auto right= findMedian(prefixSum, i,N);
            long long mini= min(left.first, right.first);
            long long maxi= max(left.second, right.second);
            ans= min(ans, maxi-mini);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        long long ans = ob.minDifference(N, A);
        cout<<ans<<endl;
    }
    return 0;
} 
// } Driver Code Ends