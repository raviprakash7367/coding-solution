
/*
    name= search a 2d matrix
    link- https://leetcode.com/problems/search-a-2d-matrix/
    author- Parth garg
    time complexity- o(log m + log n)
    space complexity- o(1)
    method 1- firstly search in vertical direction then seach in horizontal direction using binary search;
*/


class Solution {
public:
    
    int checkVertical(vector<vector<int>>&matrix, int target,int l, int r)
    {
        int mid= (l+r)/2;
        if(l<r)
        {     
            if(matrix[mid][0]== target) return mid;
            else if(matrix[mid][0]> target) return checkVertical(matrix, target,l,mid-1);
            else if(matrix[mid][0]< target) return checkVertical(matrix, target,mid+1, r);
        }
        return mid;
    }
    int checkHorizontal(vector<vector<int>>&matrix,int target,int row,int l, int r)
    {
        int mid= (l+r)/2;
        if(l<r)
        {
            if(matrix[row][mid]== target) return mid;
            else if(matrix[row][mid]>target) return checkHorizontal(matrix,target,row,l,mid-1);
            else if(matrix[row][mid]<target) return checkHorizontal(matrix,target,row,mid+1,r);
        }
        return mid;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int width= matrix[0].size();
        int height= matrix.size();
        
        int row= checkVertical(matrix,target,0,height-1);
        if(matrix[row][0]== target) return true;
        else if(matrix[row][0]> target) row= (row!=0)? row-1 :row ; 
        
        int column= checkHorizontal(matrix, target,row,0, width-1);
        if(matrix[row][column]!= target) return false;
        else return true;
        
    }
};