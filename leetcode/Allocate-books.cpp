/*
    name= Allocate Books
    link- https://www.interviewbit.com/problems/allocate-books/
    author- Parth garg
    time complexity- o(n* logn)
    space complexity- o(1)
    method 1- fix the number of pages using binary search 
        and then check how many number of students we need;
*/



bool check(vector<int>&A, int mid, int B)
{
    int n= A.size();
    if(A[0]>mid) return false;
    
    int count=1;
    int s=A[0];
    for(int i=1;i<n;i++)
    {
        if(A[i]> mid) return false;
        
        if(s+ A[i] <= mid )
        {
            s+= A[i];
        }
        else
        {
            s= A[i];
            count++;
        }
    }
    if(count>B) return false;
    else return true;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size()< B) return -1;
    int n= A.size();
    int sum=0;
    int ans= -1;
    
    for(int i=0;i<n;i++)
    {
        sum+= A[i];
    }
    int low= 0,high= sum;
    while(low<=high)
    {
        int mid= low+ (high-low)/2;
        
        if(check(A,mid,B))
        {
            ans= mid;
            high= mid-1;
        }
        else 
        {
            low= mid+1;
        }
    }
    return ans;
}
