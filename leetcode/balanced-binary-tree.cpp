/*
    name= Balanced binary tree
    link- https://leetcode.com/problems/balanced-binary-tree/
    author- Parth garg
    time complexity- o(n)
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
    bool ans;
    int check(TreeNode* root)
    {
        if(!root) return 0;
        if(!ans) return -1;
        
        int leftHeight= check(root->left);
        int rightHeight= check (root->right);
        
        if(abs(leftHeight-rightHeight)>1) 
        {
            ans= false;
            return -1;
        }
        return max(leftHeight,rightHeight)+1;
        
        
    }
    bool isBalanced(TreeNode* root) {
        ans= true;
        int temp= check(root);
        return ans;
        
    }
};