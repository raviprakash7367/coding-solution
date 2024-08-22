/*
    name= powerfull integer
    link- https://practice.geeksforgeeks.org/problems/d894706c496da5c5a4f45b0360c7f4164c516f83/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1;
*/

class Solution{
public:
    
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        map<int,int>v;
        for(int i=0;i<n;i++){
            v[intervals[i][0]]+= 1;
            v[intervals[i][1]+1]-= 1;
            v[intervals[i][1]]+= 0;
        }
        
        int sum= 0;
        int ans= -1;
        for(auto val :v){
            sum+= val.second;
            if(sum<0) sum= 0;
            if(sum>=k) ans= val.first;
        }
        
        return ans;
    }
};