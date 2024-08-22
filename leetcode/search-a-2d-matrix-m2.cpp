
/*
    name= search a 2d matrix
    link- https://leetcode.com/problems/search-a-2d-matrix/
    author- Parth garg
    time complexity- o(log (m) + log(n))
    space complexity- o(1)
    method 1- using use a variable as a product of row and column we get row by dividing and column by taking modulo
*/


class Solution {
public:
    
   
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int width= matrix[0].size();
        int height= matrix.size();
        
        int end= (width*height) -1;
        int start=0;
        
        while(start<=end)
        {
            int mid= (start+end)/2;
            int x= matrix[mid/width][mid%width];
            if(target==x) return true;
            else if(target> x) 
            {
                start= mid+1;
            }
            else end= mid-1;
        }
        
        return false;
    }
};