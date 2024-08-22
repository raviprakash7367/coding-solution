
/*
    name= minimum depth of binary tree
    link- https://leetcode.com/problems/minimum-depth-of-binary-tree/
    author- Parth garg
    time complexity- o(n)
    method 1
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
    int depth(TreeNode* root)
    {
        if(!root) return 0;
        
        int leftHgt= depth(root->left);
        int rightHgt= depth(root->right);
        if((leftHgt==0 && rightHgt==0) || (leftHgt!=0 && rightHgt!=0))
        return min(leftHgt,rightHgt) +1 ;
        
        else return max(leftHgt,rightHgt) +1 ;
    }
    
    int minDepth(TreeNode* root) {
        return depth(root);
    }
};