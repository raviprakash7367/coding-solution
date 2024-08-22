/*
    name= univalued binary tree
    link- https://leetcode.com/problems/univalued-binary-tree/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1- tree traversal using recursion;
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
    
    bool check(TreeNode* root, int prev)
    {
        if(!root) return true;
        
        if(root->val != prev)
            return false;
        return check(root->left, root->val) & check(root->right,root->val);
        
    }
    bool isUnivalTree(TreeNode* root) {
        return check(root, root->val);
    }
};