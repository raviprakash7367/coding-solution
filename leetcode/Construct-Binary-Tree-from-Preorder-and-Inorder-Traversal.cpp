/*
    name= Construct Binary Tree from Preorder and Inorder Traversal
    link- https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
    author- Parth garg
    time complexity- o(n^2)- if we use unordered map then we can do this in o(n) but then space complexity will be o(n)
    space complexity-o(1)
    method 1;
*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void constructTree(TreeNode* root,vector<int>& preorder, vector<int>& inorder,int l,int r,int idx )
    {
        root->val= preorder[idx];
        
        int midIndex;
        for(int i=l;i<=r;i++)
        {
            if(inorder[i]== root->val)
            {
                midIndex= i;
                break;
            }
        }
        
        if(idx+1 < preorder.size() && l<=midIndex-1) 
        {   
            TreeNode* newNode= new TreeNode();
            root->left= newNode;
            constructTree(root->left,preorder,inorder,l,midIndex-1,idx+1);
        }
        if(idx+1+midIndex-l < preorder.size() && midIndex+1<=r)       
        {
            TreeNode* newNode2= new TreeNode();
            root->right= newNode2;
            constructTree(root->right,preorder,inorder,midIndex+1,r,idx+1+midIndex-l);
        }
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root= new TreeNode;
        
        constructTree(root,preorder,inorder,0,preorder.size()-1, 0);
        return root;
        
        
    }
};