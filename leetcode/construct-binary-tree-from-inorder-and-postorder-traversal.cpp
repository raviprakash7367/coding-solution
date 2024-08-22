/*
    name= Construct Binary Tree from inorder and postorder Traversal
    link- https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    void constructTree(TreeNode* root,vector<int>& postorder, vector<int>& inorder,int l,int r,int idx )
    {
        root->val= postorder[idx];
        
        int midIndex;
        for(int i=l;i<=r;i++)
        {
            if(inorder[i]== root->val)
            {
                midIndex= i;
                break;
            }
        }
        
        if(idx-(r-midIndex+1) >=0 && l<=midIndex-1) 
        {   
            TreeNode* newNode= new TreeNode();
            root->left= newNode;
            constructTree(root->left,postorder,inorder,l,midIndex-1,idx-(r-midIndex+1));
        }
        if( idx-1 >=0 && midIndex+1<=r)       
        {
            TreeNode* newNode2= new TreeNode();
            root->right= newNode2;
            constructTree(root->right,postorder,inorder,midIndex+1,r,idx-1);
        }
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root= new TreeNode;
        
        constructTree(root,postorder,inorder,0,postorder.size()-1, postorder.size()-1);
        return root;
        
    }
};