/*
    name= Three way partitioning
    link- https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- take 2 pointers ;
*/





class Solution{   
public:
    
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        int n= arr.size();
        int start=0,end= n-1;
        for(int i=0; i<=end;)
        {
            if(arr[i]<a) swap(arr[i++],arr[start++]);
            else if(arr[i]>b) swap(arr[i],arr[end--]);
            else i++;
        }
    }
};