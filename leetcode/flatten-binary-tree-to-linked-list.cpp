
/*
    name= flatten binary tree to linked list
    link-https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
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
    

    void flatten(TreeNode* root) {
        while(root)
        {
            if(root->left && root->right)
            {TreeNode *t= root->left;
            while(t->right)
            {
                t= t->right;
            }
            t->right= root->right;}
            
            if(root->left)   root->right= root->left;
                root->left= NULL;
            root= root->right;
                
        }
        
        
    }
};