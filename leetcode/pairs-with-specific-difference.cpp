/*
    name= pairs with specific difference
    link- https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 1;
*/

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        if (n==1) return 0;
        sort(arr, arr+n, greater<int>());
        int sum=0;
        for(int i=0;i<n-1;){
            if((arr[i]-arr[i+1])<k){
                sum+= (arr[i]+arr[i+1]);
                i+=2;
            }
            else{
                i++;
            }
        }
        return sum;
        
    }
};