/*
    name= rotate image
    link- https://leetcode.com/problems/rotate-image/
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(1)
    method 1;
*/



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j;
        int n= matrix[0].size();
        for(int k=0;k!= n/2; k++)
        {
            i=k;
            j=k;
            int last= n-k-1;
            int t=0;
            while(j<last)
            {
                int temp= matrix[i][j];
                swap(temp, matrix[i+t][last]);
                swap(temp, matrix[last][last-t]);
                swap(temp, matrix[last-t][k]);
                matrix[i][j]= temp;
                t++;
                j++;
            }
        }
        
    }
};