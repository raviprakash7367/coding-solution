/*
    name= count inversion
    link- https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1- take the help of merge sort algorithm;
*/




#include <bits/stdc++.h> 
using namespace std;
long long merge(long long arr[], long long l, long long r,long long mid)
{

    long long n1= mid-l;
    long long n2= r-mid+1;
    long long temp[n1+n2];
    long long inv=0;
    long long i=l,j= mid;
    long long k=0;

    while(i<= mid-1 && j<= r)
    {
        if(arr[i]>arr[j])
        {
            temp[k++]= arr[j++];
            inv+= (mid-i);
        }
        else
        {
            temp[k++]= arr[i++];
        }   
        
    }
    while(i<=mid-1)temp[k++]= arr[i++];

    while(j<=r)temp[k++]= arr[j++];
    
    long long t=0;
    for(long long i=l;i<=r;i++)
    {
        arr[i]= temp[t++];
    }

    return inv;
    
}


long long mergesort(long long arr[], long long l, long long r)
{
    long long inv= 0;
    long long mid = (l+r)/2;
    if(l<r)
    {
        inv+= mergesort(arr, l,mid);
        inv+= mergesort(arr,mid+1, r);
        inv+= merge(arr,l,r,mid+1);
    }
    return inv;
}



long long getInversions(long long arr[], long long n){
    long long inversion = mergesort(arr,0,n-1);    
    return inversion;
}