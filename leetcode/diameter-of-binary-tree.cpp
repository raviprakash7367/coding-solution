/*
    name= diameter of binary tree
    link- https://leetcode.com/problems/diameter-of-binary-tree/
    author- Parth garg
    time complexity- o(n)
    method 1- Max value of Height(leftSubtree)+Height(rightSubtree) (at any node )
    is the diameter. Keep track of maxium diameter duing traversal and find the height of the tree.;
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
    int leaf(TreeNode* root,int& depth)
    {
        if(!root) return 0;
        
        int leftDepth= leaf(root->left,depth);
        int rightDepth= leaf(root->right,depth);
        depth= max(depth, leftDepth+rightDepth);
        return max(leftDepth,rightDepth)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int depth=0;
        leaf(root,depth);
        return depth;
    }
};