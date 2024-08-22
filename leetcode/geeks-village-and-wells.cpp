/*
    name= geek's village and wells
    link- https://practice.geeksforgeeks.org/problems/5a1277ffc1ec1d3a63d1a5d6b3920dd3d1294261/1
    author- Parth garg
    time complexity- o(n*m)
    space complexity- o(n*m)
    method 1- bfs;
*/
class Solution{
public:
    void solveBFS(vector<vector<int>>&vis,vector<vector<int>>&res,vector<vector<char>>&c){
        int n= c.size();
        int m= c[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    q.push({i,j});
                    vis[i][j]=1;
                    res[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            int x= q.size();
            for(int k=0;k<x;k++){
                auto p= q.front();
                int i= p.first;
                int j= p.second;
                
                if(i-1>=0 && vis[i-1][j]== -1 &&(c[i-1][j]=='H' || c[i-1][j]=='.')){
                    vis[i-1][j]=1;
                    q.push({i-1,j});
                    res[i-1][j]= 2+ res[i][j];
                }
                if(i+1 <n && vis[i+1][j]== -1 && (c[i+1][j]=='H' || c[i+1][j]=='.')){
                    vis[i+1][j]=1;
                    q.push({i+1,j});
                    res[i+1][j]= 2+ res[i][j];
                }
                if(j-1>=0 && vis[i][j-1]== -1 && (c[i][j-1]=='H' || c[i][j-1]== '.')){
                    vis[i][j-1]=1;
                    q.push({i,j-1});
                    res[i][j-1]= 2+ res[i][j];
                }
                if(j+1<m && vis[i][j+1]== -1 && (c[i][j+1]=='H' || c[i][j+1]== '.')){
                    vis[i][j+1]=1;
                    q.push({i,j+1});
                    res[i][j+1]= 2+ res[i][j];
                }
                q.pop();
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='N' || c[i][j]=='.'){
                    res[i][j]=0;
                }
                else if(vis[i][j] == -1){
                    res[i][j]= -1;
                }
            }
        }
        
    }
    
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        vector<vector<int>>vis(n,vector<int>(m,-1));
        vector<vector<int>>res(n,vector<int>(m));
        solveBFS(vis,res,c);
        return res;
    }
};