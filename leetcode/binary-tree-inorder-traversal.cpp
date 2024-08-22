
/*
    name= binary tree inorder traversal
    link- https://leetcode.com/problems/binary-tree-inorder-traversal/
    author- Parth garg
    time complexity- o(n)
    method 1- make the recursion left->root->right;
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
    void inorderTraversal(vector<int>&result, TreeNode* root)
    {
        // left->root->right
        if(root== NULL) return;
        
        inorderTraversal(result, root->left);
        result.push_back(root->val);
        inorderTraversal(result, root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        inorderTraversal(result, root);
        return result;
    }
};