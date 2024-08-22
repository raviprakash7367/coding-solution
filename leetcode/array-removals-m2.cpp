/*
    name= array removal
    link- https://practice.geeksforgeeks.org/problems/array-removals/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(1)
    method 2- sliding window;
*/

class Solution{
    public:
    int removals(vector<int>& arr, int k){
        int n= arr.size();
        if(n==1) return 0;
        int l=0,r=0;
        int maxLen=0;
        int len=1;
        sort(arr.begin(),arr.end());
        while(r < n-1 ){
            if(r == l){
                if(arr[r+1]-arr[r] >k){
                    l++;
                    r++;
                    len= 1;
                }
                else{
                    r++;
                    len++;
                }
            }
            else if(arr[r+1]- arr[l] <= k){
                r++;
                len++;
            }
            else {
                l++;
                len--;
            }
            maxLen= max(maxLen, len); 
        }
        return n-maxLen;
    }
};