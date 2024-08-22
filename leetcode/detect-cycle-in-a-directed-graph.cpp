/*
    name= Detect cycle in a directed graph
    link- https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
    author- Parth garg
    time complexity- o(v+e)
    space complexity- o(v)
    method 1;
*/

class Solution {
  public:
    bool dfs(vector<int>adj[], vector<int>& vis,vector<int>& dfsVis, int node){
        vis[node]=1;
        dfsVis[node]= 1;
        
        for(auto child : adj[node]){
            if(dfsVis[child]) return true;
            else if(vis[child] ==0) {
                if(dfs(adj,vis,dfsVis,child)) return true;
            }
        }
        dfsVis[node]= 0;
        return false;
    }
    
    
    bool isCyclic(int V, vector<int> adj[]) {
       vector<int>vis(V,0),dfsVis(V,0);
       
       for(int i=0;i<V;i++){
           if(vis[i]==0){
               if(dfs(adj,vis,dfsVis,i))return true;
           }
       }
       return false;
    }
};