/*
    name= flood fill algorithm
    link- https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
    author- Parth garg
    time complexity- o(n*m) (worst case when all nodes are of same color)
    space complexity- o(n*m)
    method 1;
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if(newColor == color) return image;
        int n= image.size();
        int m= image[0].size();
        stack<pair<int,int>>st;
        st.push({sr,sc});
        
        while(!st.empty()){
            int i = st.top().first;
            int j = st.top().second;
            
            image[i][j] = newColor;
            if(i-1 >= 0 && image[i-1][j] == color){
                st.push({i-1,j});
            }
            else if(i+1 < n && image[i+1][j] == color){
                st.push({i+1,j});
            }
            else if(j-1 >=0 && image[i][j-1] == color ){
                st.push({i,j-1});
            }
            else if(j+1 < m && image[i][j+1] == color){
                st.push({i,j+1});
            }
            else{
                st.pop();
            }
        }
        
        return image;
    }
};