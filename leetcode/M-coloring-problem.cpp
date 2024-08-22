/*
    name= M-Coloring Problem
    link- https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#
    author- Parth garg
    time complexity-  O(M^N)
    space complexity- o(N)
    method 1- backtracking and recursion;
*/



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
   
   bool check(bool graph[101][101],int vertex,int clr,int n,int colors[])
   {
       for(int i=0;i<n;i++)
       {
           if(graph[vertex][i])
           {
               if(colors[i]==clr)return false;
           }
       }
       return true;
   }
   
   bool solve(bool graph[101][101],int vertex,int n,int m,int colors[])
   {
       if(vertex== n) return true;
       
       for(int j=1;j<=m;j++)
        {
            if(check(graph,vertex,j,n,colors))
            {
                colors[vertex]=j;
                if(solve(graph,vertex+1,n,m,colors))return true;
                colors[vertex]=-1;
            }
            
        }
        return false;
   }
    bool graphColoring(bool graph[101][101], int m, int n) {
        int colors[n]={-1};
        
        
        return solve(graph,0,n,m,colors);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends