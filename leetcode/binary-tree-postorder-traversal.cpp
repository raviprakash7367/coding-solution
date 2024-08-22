/*
    name= binary tree postorder traversal
    link- https://leetcode.com/problems/binary-tree-postorder-traversal/
    author- Parth garg
    time complexity- o(n)
    method 1- left->right->root ;
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
    vector<int>result;
    void Postorder(TreeNode* root)
    {
        if(!root) return ;
    
        Postorder(root->left);
        Postorder(root->right);
        result.push_back(root->val);
        
    }
    vector<int> postorderTraversal(TreeNode* root) {
        Postorder(root);
        return result;
    }
};