/*
    name= maximum depth of binary tree
    link- https://leetcode.com/problems/maximum-depth-of-binary-tree/
    author- Parth garg
    time complexity- o(n)
    method 1- recursively check for max depth in left and right part of every sub tree;
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
    int depth(TreeNode* root,int dep)
    {
        if(!root) return dep;
        dep++;
        int result= max(depth(root->left,dep),depth(root->right,dep));
        return result;
    }
    int maxDepth(TreeNode* root) {
        return depth(root,0);
    }
};