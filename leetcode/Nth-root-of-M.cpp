/*
    name= Nth Root Of M
    link- https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
    author- Parth garg
    time complexity- O(N x log(M x 10^d))
    space complexity- O(1)
    method 1- binary search;
*/


#include <bits/stdc++.h> 
using namespace std;

double Value(double number, int n)
{
    double ans= 1.0;
    for(int i=1;i<=n;i++)ans= ans*number;
    return ans;
}

double findNthRootOfM(int n, int m) {
	double low= 1;
    double high= m;
    double diff= 1e-8
    while(high-low > diff)
    {
        double mid = (high+low)/2.0;
        if(Value(mid,n) > m) 
        {
            high= mid;
        }
        else low= mid;
        
    }
    return low;
}