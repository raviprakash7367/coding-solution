
/*
    name= rotate image
    link- https://leetcode.com/problems/rotate-image/
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(1)
    method 2- after reversing the matrix(rows) we observe that we have to swap every index (i,j) with (j,i);
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j= i+1; j< matrix.size();j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
    }
};