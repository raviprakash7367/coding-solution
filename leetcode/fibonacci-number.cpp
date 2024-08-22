
/*
    name= fibonacci number
    link- https://leetcode.com/problems/fibonacci-number/
    author- Parth garg
    time complexity- o(n)
    method 1- use DP;
*/

class Solution {
public:
    int fibRecursion(vector<int>&fibo, int n)
    {
        if(n==0 || n==1) return n;
        
        if(fibo[n]!= -1) return fibo[n];
        return fibo[n]= fibRecursion(fibo,n-1)+ fibRecursion(fibo,n-2);
        
    }
    int fib(int n) {
        vector<int>fibo(31, -1);
        return fibRecursion(fibo, n);
        
    }
};