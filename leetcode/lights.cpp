/*
    name= lights
    link-  //newton school coding contest 27/10/2022   https://my.newtonschool.co/playground/code/fc9unss9j662/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n*m) for storing graph and o(n) for dp
    method 1- dfs;
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fori(i, n) for (int32_t i = 0; i < int32_t(n); i++)

int dp[100001];

int func(int source, vector<vector<int>>&graph)
{
    int path= 0;
    if(dp[source] != -1) return dp[source];
    if(graph[source].size()==0) path++;
    for(auto child: graph[source])
    {
        path+= func(child,graph);
    }
    return dp[source]= path;
    
}

int32_t main()
{
    int n,m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>graph(n+1);
    vector<int>indegree(n+1,0);
    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        indegree[v]++;
    }

    int ans=0;
    for(int i= 1;i<n+1;i++)
    {
        if(indegree[i]==0)
        ans+= func(i,graph); 
    }
    cout<<ans<<endl; 
 

    
}