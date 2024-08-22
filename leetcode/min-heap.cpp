
/*
    name= Min Heap
    link- https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
    author- Parth garg
    time complexity- o(logn) 
    space complexity- o(1)
    method 1- implementation of min heap;
*/


#include <bits/stdc++.h> 
using namespace std;

void insert(vector<int>&heap, int val)
{
    heap.push_back(val);
    int index= heap.size()-1; //index of new entry 
    if(index==0) return ;
    
    while(index>0)
    {
        int parent= (index-1)/2;
        if(heap[parent]>heap[index])
        {
            swap(heap[parent],heap[index]);
            index= parent;
        }
        else return;
    }
}

void del(vector<int>&heap, vector<int>&result)
{
    int size= heap.size();
    if(size==0) 
    {
        result.push_back(-1);
        return;
    }
    result.push_back(heap[0]);
    heap[0]= heap[size-1];
    heap.pop_back();
    
    int index=0;
    while(index<(size-1))
    {  
        int prev= index;
        int leftChild=(2*index)+1;
        int rightChild= (2*index)+2;
        if(leftChild<size && heap[index]>heap[leftChild])
        {
            index= leftChild;
        }
        if(rightChild<size && heap[index]>heap[rightChild])
        {
            index= rightChild;
        }
        if(index!= prev)
        {
            swap(heap[index],heap[prev]);
        }
        else return;
    }
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>heap;
    vector<int>result;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0) insert(heap,q[i][1]);
        else if(q[i][0]==1) del(heap,result);
    }
    return result;
    
    
}
