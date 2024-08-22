/*
    name= Finf if path exists in graph
    link- https://leetcode.com/problems/find-if-path-exists-in-graph/
    author- Parth garg
    time complexity- o(n)
    method 1- use dfs ;
*/


class Solution {
public:
    vector<int>g[200010];    
    void dfs(int n,bool vis[])
    {
        if(vis[n]==true) return;
        vis[n]=true;
        for(int i=0;i < g[n].size();i++)
        {
            int child= g[n][i];
            dfs(child,vis);
        }
        return;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        bool vis[n];
        for(int i=0;i<n;i++)
        vis[i]= false;

        for(int i=0;i<edges.size();i++)
        {
            int u= edges[i][0];
            int v= edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(source,vis);

        if(!vis[destination]) return false;
        else return true;

    }
};