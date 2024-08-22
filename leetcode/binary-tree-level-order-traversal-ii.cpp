/*
    name= binary tree level order traversal ii
    link-https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
    author- Parth garg 
    time complexity- o(n)
    space complexity- o(n) for storing result
    method 1- firstly find the depth of the tree;
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
    
    int maxDepth(TreeNode * root)
    {
        if(!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
    
    void traversal(TreeNode* root,int level,vector<vector<int>>&result)
    {
        if(!root) return;
        result[level].push_back(root->val);     
        traversal(root->left, level-1, result);
        traversal(root->right,level-1, result);
        
    }    
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int Depth= maxDepth(root);
        vector<vector<int>>result(Depth,vector<int>());
        traversal(root, Depth-1, result);
        return result;
    }
};