/*
    name= delete node in a bst
    link- https://leetcode.com/problems/delete-node-in-a-bst/description/
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(logn)
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;

        if(root->val== key){
            //if root is leaf
            if(!root->left && !root->right){
                return NULL;
            }//if only right is null
            else if(!root->right){
                root= root->left;
                
            } //if only left is null
            else if(!root->left){
                root= root->right;
                
            }
            else{
                TreeNode *temp = root->right;
                while(temp->left != NULL){
                    temp= temp->left;
                }
                root->val= temp->val;
                root->right= deleteNode(root->right, temp->val);
                
            }
            return root;
        }
        else if(root->val < key){
            root->right=  deleteNode(root->right, key);
            return root;
        }
        else {
            root->left= deleteNode(root->left, key);
            return root;
        }
    }
};