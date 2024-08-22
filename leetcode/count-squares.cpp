/*
    name= count squares
    link- https://practice.geeksforgeeks.org/problems/count-squares3649/1
    author- Parth garg
    time complexity- o(logn) 
    space complexity- o(1)
    method 1;
*/

class Solution {
  public:
    int countSquares(int N) {
        int l=1,r=N;
        
        while(l<=r){
            int mid= l+(r-l)/2;
            long long x= mid*1LL*mid;
            if(x== N){
                return mid-1;
            }
            else if(x<N){
                l= mid+1;
            }
            else{
                r= mid-1;
            }
        }
        return l-1;
    }
};