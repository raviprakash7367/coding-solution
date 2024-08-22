/*
    name=  Maximum sum of Non-adjacent nodes
    link-  https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(height)
    method 1;
*/

class Solution{
  public:
    pair<int,int>solve(Node *root){
        if(!root) return {0,0};
        
        pair<int,int>res,left,right;
        left= solve(root->left);
        right= solve(root->right);
        
        res.first= root->data + left.second + right.second ;
        res.second= max(left.second,left.first)+ max(right.second,right.first);
        
        return res;
        
    }
    int getMaxSum(Node *root) 
    {
        if(!root) return 0;
        pair<int,int>res= solve(root);
        return max(res.first, res.second);
    }
};