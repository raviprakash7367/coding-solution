/*
    name= Minimum Lights to Activate
    link- https://www.interviewbit.com/problems/minimum-lights-to-activate/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1= always take the last active bulb in the corresponding range;
*/


int Solution::solve(vector<int> &A, int B) {
    if(B==0) return -1;
    int n= A.size();
    int i=0;
    int ans=0;
    while(i<n)
    {
        int idx= -1;
        for(int j= max(i-B+1,0) ; j<= min(n, i+B-1); j++)
        {
            if(A[j]==1)
                idx= j;
        }
        if(idx== -1) return -1;
        ans++;
        i= idx+ B;
    }
    return ans;
}
