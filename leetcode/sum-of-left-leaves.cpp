/*
    name= sum of left leaves
    link- https://leetcode.com/problems/sum-of-left-leaves/
    author- Parth garg
    time complexity- o(n)
    method 1- add only when the function is called for left node;
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
    int sum;
    int Traverse(TreeNode* root)
    {
        if(!root) return 0 ;
        
        if(!root->left && !root->right)
            return root->val;
        
        int l=Traverse(root->left);
        sum+= l;
        int r= Traverse(root->right);
        
        return 0;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int i= Traverse(root);
        return sum;
    }
};