/*
    name= Disarrangement of balls
    link-  https://practice.geeksforgeeks.org/problems/dearrangement-of-balls0918/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/

class Solution{
public:
    const int m= 1e9+7;
    long int disarrange(int N){
        if(N==1) return 0;
        long int prev= 0, nextPrev= 1;
        long int ans= 0;
        // relation =    f(n) = (n-1)*(f(n-1)+f(n-2))
        for(int i=2;i<=N;i++){
            ans= ((i-1)*1LL*(prev+nextPrev))%m;
            nextPrev= prev;
            prev= ans;
        }        
        
        return ans;
    }
};