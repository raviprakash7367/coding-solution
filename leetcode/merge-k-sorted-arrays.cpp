
/* 
    name= merge k sorted arrays
    link- https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379
    author- Parth garg
    time complexity- k*n log(k*n)
    space complexity- k*n
    method 1- min heap ;
*/

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<kArrays[i].size();j++)
            p.push(kArrays[i][j]);
        
    }
    vector<int>result;
    while(p.size()>0)
    {
        result.push_back(p.top());
        p.pop();
    }
    return result;
}
