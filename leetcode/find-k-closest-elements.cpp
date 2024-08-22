/*
    name= https://leetcode.com/problems/find-k-closest-elements/description/ 
    link- find-k-closest-elements
    author- Parth garg
    time complexity- o(k+ log (n-k))
    space complexity- o(k) for returning result
    method 1 - try to find the starting point of resulting array;
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n= arr.size();
        int l=0, r= n-k;

        while(l<r){
            int mid = l+ (r-l)/2;
            if(x-arr[mid] > arr[mid+k]-x){
                l= mid+1;
            }
            else{
                r= mid;
            }
        }
        vector<int>res(k);
        for(int i= 0;i<k;i++){
            res[i]= arr[i+l];
        }
        return res;

    }
};