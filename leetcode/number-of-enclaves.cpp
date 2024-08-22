/*
    name=  Number of Enclaves
    link-  https://leetcode.com/problems/number-of-enclaves/description/
    author- Parth garg
    time complexity-  o(n*m)
    space complexity- o(n*m)
    method 1;
*/

class Solution {
public:
    int bfs(int n, int m, vector<vector<int>>&grid,vector<vector<int>>&vis , bool &flag)
    {
        int x=grid.size(),y=grid[0].size();
        queue<pair<int,int>>q;
        q.push({n,m});
        int count =0;
        vis[n][m] = 1;
        while(!q.empty()){
            int i,j;
            i= q.front().first;
            j= q.front().second;
            q.pop();count ++;
            
            if(i==0 || i== x-1 || j==0 || j== y-1)flag= true;

            if(i-1 >=0 && grid[i-1][j] == 1 && vis[i-1][j] == 0){
                q.push({i-1,j});
                vis[i-1][j] = 1;
            }
            if(i+1 < x && grid[i+1][j] == 1 && vis[i+1][j] == 0){
                q.push({i+1,j});
                vis[i+1][j] = 1;
            }
            if(j-1 >=0 && grid[i][j-1] == 1 && vis[i][j-1] == 0){
                q.push({i,j-1});
                vis[i][j-1] = 1;
            }
            if(j+1 < y && grid[i][j+1] == 1 && vis[i][j+1] == 0){
                q.push({i,j+1});
                vis[i][j+1] = 1;
            }
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    bool flag= false;
                    int temp = bfs(i,j,grid,vis,flag);
                    if(flag == false){ count+= temp;}
                }
            }
        }
        return count;
    }
};