/*
    name= factorials of large number
    link- https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1
    author- Parth garg
    time complexity- o(n^2)
    space complexity-o(n)
    method 1;
*/


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>result;
        result.push_back(1);
        for(int i=2;i<=N;i++)
        {
            long long carry= 0;
            for(int j=0;j<result.size();j++)
            {
                long long sum= (result[j]*i)+carry;
                carry= sum/10;
                result[j]= sum%10;
            }
            if(carry!=0)
            {
                while(carry>0)
                {
                    result.push_back(carry%10);
                    carry/=10;
                }
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends