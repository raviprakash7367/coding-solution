/*
    name= second minimum node in a binary tree
    link- https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
    author- Parth garg
    time complexity- o(n)
    method 1- call function for left and right node if any of them is negative then return other 
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
    
    
    int secondmin(TreeNode* root, int mini)
    {
        if(root==NULL) return -1 ;
        if(root->val != mini ) return root->val;
        int left= secondmin(root->left,mini);
        int right= secondmin(root->right,mini);
        
        if(left==-1) return right;
        else if(right== -1) return left;
        else return min(left,right);

    }
    int findSecondMinimumValue(TreeNode* root) {
        int ans= secondmin(root, root->val);
        return ans;
    }
};