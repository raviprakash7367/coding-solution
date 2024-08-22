
/*
    name= binary tree preorder traversal
    link- https://leetcode.com/problems/binary-tree-preorder-traversal/
    author- Parth garg
    time complexity- o(n)
    method 1- root->left->right order;
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
    void Preorder(TreeNode* root)
    {
        if(!root) return ;
        
        result.push_back(root->val);
        Preorder(root->left);
        Preorder(root->right);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        Preorder(root);
        return result;
        
    }
};