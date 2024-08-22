/*
    name= evaluate boolean binary tree
    link- https://leetcode.com/problems/evaluate-boolean-binary-tree/
    author- Parth garg
    time complexity- O(n)
    method 1- use recursion;
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
    bool evaluateTree(TreeNode* root) {
        if(root->val == 1) return true;
        else if(root->val ==0) return false;
        bool l,r;
        
        l= evaluateTree(root->left);
        r= evaluateTree(root->right);
                
        if(root->val == 2) return (l || r);
        else return (l && r);
        
    }
};