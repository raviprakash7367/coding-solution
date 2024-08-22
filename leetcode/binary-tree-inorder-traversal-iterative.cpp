/*
    name= binary tree inorder traversal
    link- https://leetcode.com/problems/binary-tree-inorder-traversal/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1- iterative;
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
    
    vector<int> inorderTraversal(TreeNode* root) {
        // root->left->right
        vector<int>tree;
        stack<TreeNode*> s;
        TreeNode* curr= root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr= curr->left;
            }
            curr= s.top();
            tree.push_back(curr->val);
            s.pop();
            curr= curr->right;
        }
        return tree;

    }
};