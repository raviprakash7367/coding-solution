/*
    name= matrix median
    link-  https://www.interviewbit.com/problems/matrix-median/
    author- Parth garg
    time complexity- o(30*nlog m)
    space complexity- o(1)
    method 1- binary search ;
*/


int Solution::findMedian(vector<vector<int> > &A) {
    int n= A.size();
    int m= A[0].size();
    int k= (n*m)/2;
    
    int low= 1;
    int high= 1e9;
    while(low<=high)
    {
        long long num= (low+high)/2;
        // now find the no. of elements less than mid
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            int l=0,r= m-1;
            while(l<=r)
            {
                int mid= (l+r)/2 ;
                if(A[i][mid] <= num)
                {
                    l= mid+1;
                }
                else 
                {
                    r= mid-1;
                }
            } 
            count+= l;
        }
        if(count<= k) low= num+1;
        else high= num-1; 
    }
    return low;
     
}
