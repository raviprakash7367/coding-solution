
/*
    name= Find a Corresponding Node of a Binary Tree in a Clone of That Tree
    link- https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
    author- Parth garg
    time complexity- o(n)
    method 1- use dfs pre order traversal that is root->left->right order ;
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    void search( TreeNode* root,TreeNode* target,TreeNode* &result)
    {   
        if(root== NULL) return;
        if(root->val== target->val) 
        {
            result = root;
            return;
        }
        search(root->left, target,result);
        search(root->right, target,result);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result;
        search(cloned, target,result);
        return result;
    }
};