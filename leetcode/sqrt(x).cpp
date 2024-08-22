/*
    ques name- sqrt(x)
    link- https://leetcode.com/problems/sqrtx/
    author- parth garg
    time complexity = 10^5 to 10^6 iterations
    method 1- check i^2 < x from 0 to where we found our condition true 
*/

class Solution {
public:
    int mySqrt(int x) {
        
        long long i=0;
        while(i*i<=x)
        {
            i++;
        }
        return i-1;
    }
};

 // method 2- use sqrt(x) function 
 // time complexity-> o(logn)
class Solution {
public:
    int mySqrt(int x) {     
        long long i= sqrt(x);
        return i;
    }
};


// method 3- use binary search 
//time complexity- > o(logn)
class Solution {
public:
    int mySqrt(int x) {
        
        int start= 0;
        int end =x;
        long long temp,t1;
        long long mid;
        if(x==1|| x==0) return x;
        while(start<end)
        {
            mid= (start+end)/2;
            temp= mid*mid;
            t1= (mid+1)*(mid+1);
            if(t1 >x && temp <=x) return mid;
            else if(temp > x) end= mid-1;
            else if(temp <x) start= mid+1;
        }
        return end;
    }
};
