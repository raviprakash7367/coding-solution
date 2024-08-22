/*
    name= largest rectangular sub matrix whose sum is 0
    link- https://practice.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1
    author- Parth garg
    time complexity- o(n*n*m)
    space complexity- o(n*m)
    method 1;
*/


class Solution{
  public:
  
  pair<int,int>findMaxcoordinates(vector<int>&dp){
    int n= dp.size() ;
    int arr[n+1];arr[0]=0;
    int st= -1, end= -1;
    for(int i=1;i<n+1;i++)
    {
        arr[i]= arr[i-1]+dp[i-1];
    }
    
    int ans=0,x=0;
    unordered_map<int,int>m;
    for(int i=1;i<n+1;i++)
    {
        if(m.find(arr[i])== m.end()) m[arr[i]]= i;
        else
        {
            x= i-m[arr[i]];
            if(x>ans){
                st = m[arr[i]];
                end= i-1;
                ans = x;
            }
            else if(x== ans){
                if(m[arr[i]]-1 < st){
                    st= m[arr[i]];
                    end= i-1;
                }
            }
        }
        if(arr[i]==0)
        {
            ans= i;
            st= 0,end=i-1;
        }
    }

    return {st,end};
    
  }
  
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int n= a.size();
      int c= a[0].size();
      int maxArea = 0;
      int sti= -1,endi= -1,stj= -1,endj= -1;
      for(int i=0;i<n;i++){
          vector<int>dp(c,0);
          for(int j= i;j<n;j++){
              for(int k= 0; k<c;k++){
                  dp[k]+= a[j][k];
              }
              pair<int,int>p = findMaxcoordinates(dp);
              int a1,a2, b1,b2;
              a1= i;a2=p.first;
              b1= j;b2=p.second;
              if(a2== -1) continue;
              int area= (b2-a2+1)*1LL*(b1-a1+1);
              if(area > maxArea){
                  maxArea= area;
                  sti= a1;
                  stj= a2;
                  endi= b1;
                  endj= b2;
              }
              else if(area== maxArea){
                  if(a2 < stj || a1 < sti){
                      sti= a1;
                      stj= a2;
                      endi= b1;
                      endj= b2;
                  }
              }
          }
      }
      
      if(sti != -1){
        vector<vector<int>>res(endi-sti+1, vector<int>(endj-stj+1));
        for(int i= sti; i<=endi;i++){
            for(int j= stj; j<= endj;j++){
                res[i-sti][j-stj] = a[i][j];
            }
        }
        return res;
      }
      else {
          vector<vector<int>>res(0,vector<int>(0));
          return res;
      }
    
  }
};