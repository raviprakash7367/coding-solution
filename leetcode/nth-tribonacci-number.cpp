/*
    name= nth tribonacci number
    link- https://leetcode.com/problems/n-th-tribonacci-number/submissions/
    author- Parth garg
    time complexity- o(n)
    method 1- make static array for saving the ith tribonacci
*/

class Solution {
    
public:
    
    int tribonacci(int n) {
        static long long int t[38]={0};
        if(n==0) return 0;
        else if(n==1) return 1;
        else if(n==2) return 1;
        
        if(t[n]!=0) return t[n];
        
        return t[n]= tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
        
        
    }
};