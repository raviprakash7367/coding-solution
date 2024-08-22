/*
    name= transform to sum tree
    link- https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution {
  public:
  
    int findSum(Node *node){
        if(!node) return 0;
        
        int leftSum= findSum(node->left);
        int rightSum= findSum(node->right);
        
        int x= node->data;
        node->data= leftSum+ rightSum;
        return x+ node->data;
    }
    
    
    void toSumTree(Node *node)
    {
        int x= findSum(node);
        return ;
    }
};