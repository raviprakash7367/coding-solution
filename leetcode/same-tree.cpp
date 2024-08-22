/*
    name= same tree
    link- https://leetcode.com/problems/same-tree/
    author- Parth garg
    time complexity- o(n)
    method 1- on every recursion call check root value if they differs then return false;
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
    
    bool check(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return true;
        if(!p && q) return false;
        else if(!q && p) return false;
        if(p->val != q->val) return false;
        
        return check(p->left, q->left) & check(p->right,q->right);
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p,q);
    }
};