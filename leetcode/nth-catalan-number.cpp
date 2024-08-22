/*
    name= nth catalan number
    link- https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
    author- Parth garg
    time complexity- o(2*n*n)
    space complexity- o(n)
    method 1;
*/

//{ Driver Code Starts
//Initial template for C++

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find the nth catalan number.
    cpp_int findCatalan(int n) 
    {
        if(n==0) return 1;
        vector<cpp_int>dp(n+1,0);
        
        for(int i=0;i<=2*n; i++){
            for(int j= n; j>0;j--){
                dp[j]= dp[j]+dp[j-1];
            }
            dp[0]=1;
            
            // for(int i=0;i<=n;i++){
            //     cout<<dp[i]<<" ";
            // }
            // cout<<endl;
        }
        return dp[n]/(n+1);
        
        
    }
};

//{ Driver Code Starts.

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends