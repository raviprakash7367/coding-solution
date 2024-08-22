
/*
    name= powx-n
    link- https://leetcode.com/problems/powx-n/submissions/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(1)
    method 1- call function for n/2 pow and check for even or odd power ;
*/



class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0)
        {
            n= abs(n);
            x= 1/x;
        }
        return (n%2==0)? myPow(x*x, n/2): x* myPow(x*x, n/2);
    }
};