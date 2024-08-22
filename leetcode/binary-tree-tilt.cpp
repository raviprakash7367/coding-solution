/*
    name= binary tree tilt
    link- https://leetcode.com/problems/binary-tree-tilt/
    author- Parth garg
    time complexity- o(n)
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
    
    int tilt(TreeNode* root, int& sum)
    {
        if(!root) return 0;
        
        int l= tilt(root->left,sum);
        int r= tilt(root->right,sum);
        
        sum+= abs(r-l);
        
        return l+r+ root->val; 
        
    }
    
    int findTilt(TreeNode* root) {
        int sum= 0;
        tilt(root,sum);
        return sum;
    }
};