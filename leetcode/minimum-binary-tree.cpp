/*
    name=minimum binary tree
    link- https://leetcode.com/problems/maximum-binary-tree/
    author- Parth garg
    time complexity- o(n^2)
    space complexity- o(n)
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
    int vis[1001];
    TreeNode* tree(vector<int>&nums, int l, int r)
    {
        if(l>r) return NULL;
        
        int max= INT_MIN;
        int index;
        for(int i= l; i<=r;i++)
        {
            if(nums[i]>max)
            {    
                max= nums[i];
                index= i;
            }
        }
 
        TreeNode* root= new TreeNode();
        root->val = max;
    
        root->left= tree(nums,l,index-1);
        root->right= tree(nums,index+1, r);
        return root;
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return tree(nums,0,nums.size()-1);
    }
};