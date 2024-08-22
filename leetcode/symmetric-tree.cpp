/*
    name= symmetric Tree
    link- https://leetcode.com/problems/symmetric-tree/
    author- Parth garg
    time complexity- o(n)
    method 1- recursively check for every node of left half and right half;
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
    bool check(TreeNode* root1,TreeNode* root2)
    {
        if(!root1 && root2) return false;
        if(root1 && !root2) return false;
        if(!root1 && !root2) return true;
        if(root1->val != root2->val) return false;
        
        if(check(root1->left, root2->right) && check(root1->right, root2->left))
            return true;
        return false;

    }
    
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};