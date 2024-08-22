/*
    name= Island perimeter
    link- https://leetcode.com/problems/island-perimeter/
    author- Parth garg
    time complexity- o(n*m) where n,m are length and breadth of rectangle
    method 1- total sides are (4 * no. of 1's) and we have to subtract the 2* no. of connections) 
              because we have counted that side in both the squares;
*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count=0, contact=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1) 
                {
                    count++;
                    if(i!=0 && grid[i-1][j]==1) contact++;
                    if(j!=0 && grid[i][j-1]==1) contact++;
                }
            }
        }
        return (4*count)-(2*contact);
    }
};