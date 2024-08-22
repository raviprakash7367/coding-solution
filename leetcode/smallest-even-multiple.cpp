/*
    name= smallest even multiple
    link- https://leetcode.com/problems/smallest-even-multiple/
    author- Parth garg
    time complexity- o(1)
    space complexity- o(1)
    method 1;
*/


class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0 ) return n;
        else return 2*n;
    }
};