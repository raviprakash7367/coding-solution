

/*
    name= subarray with given xor
    link- https://www.interviewbit.com/problems/subarray-with-given-xor/
    author- Parth garg
    time complexity-o(n)
    space complexity-o(n)
    method 1- firstly find the prefix xor and then use map for finding count of B^v[i] element before ith index;
*/


int Solution::solve(vector<int> &A, int B) {
    int n= A.size();
    vector<int>v(n+1);
    v[0]=0;
    for(int i=1;i<n+1;i++)
    {
        v[i]= v[i-1]^A[i-1];
        
    }
    int count=0;
    unordered_map<int,int>m;
    for(int i=1;i<n+1;i++)
    {
        
        if(m.find((B^v[i]))!= m.end())
        {
            count+= m[(B^v[i])];
        }
        if(B== v[i]) count++;
            
        m[v[i]]++;
        
    }
    
    return count;
}
