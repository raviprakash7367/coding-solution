/*
    name= binary tree to bst
    link-  https://practice.geeksforgeeks.org/problems/binary-tree-to-bst/1
    author- Parth garg
    time complexity- o(nlogn)
    space complexity- o(n)
    method 1;
*/

class Solution{
  public:
    void inorderTraversal(Node *root, vector<int>&inorder){
        if(!root) return;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
        
    }
    void makeBST(Node*root, vector<int>&inorder, int *i){
        if(!root) return;
        makeBST(root->left, inorder,i);
        root->data= inorder[*i];
        *i= *i+1;
        makeBST(root->right,inorder,i);
        
    }
    Node *binaryTreeToBST (Node *root)
    {
        if(!root ) return root;
        vector<int>inorder;
        inorderTraversal(root, inorder);
        sort(inorder.begin(),inorder.end());
        int i=0;
        makeBST(root, inorder, &i);
        return root;
    }
};