/*
    name= Unequal Arrays
    link- https://practice.geeksforgeeks.org/problems/4db2fcd97400456c4914d5a3e8ad932cc21e3e9d/1
    author- Parth garg
    time complexity- o(NlogN)
    space complexity- o(N)
    method 1;
*/


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        long long sum1=0,sum2=0;
        long long evenA=0,evenB=0;
        for(int i=0;i<N;i++){
            sum1+= A[i];
            if(A[i]%2==0)evenA++;
            sum2+= B[i];
            if(B[i]%2==0)evenB++;
        }
        
        if(evenA != evenB) return -1;
        if(sum1 != sum2) return -1;
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end()); 
        
        vector<int>oddA,oddB,evensA,evensB;
        for(int i=0;i<N;i++){
            if(A[i]&1 ) {
                oddA.push_back(A[i]);
            }
            else{
                evensA.push_back(A[i]);
            }
            if(B[i]&1 ) {
                oddB.push_back(B[i]);
            }
            else{
                evensB.push_back(B[i]);
            }
        }
        
        int count= 0;
        for(int i=0;i<oddA.size();i++){
            if(oddA[i]>oddB[i]){
                count+= ((oddA[i]-oddB[i])/2);
            }
            
        }
        for(int i=0;i<evensA.size();i++){
            if(evensA[i]>evensB[i]){
                count+= ((evensA[i]-evensB[i])/2);
            }
            
        }
        
        return count;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends