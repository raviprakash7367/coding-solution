/*
    name= binary tree zigzag level order traversal
    link-https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
    author- Parth garg
    time complexity- o(n)
    space complexity-o(n) (for saving result)
    method 1- same as binary tree level order traversal, at the end do reverse the odd numbered rows
            we can also use queue for doing this;
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
    void traversal(TreeNode* root,int level,vector<vector<int>>&result)
    {
        if(!root) return;
        if(result.size()==level) result.push_back(vector<int>());
        
        result[level].push_back(root->val);
        
        traversal(root->left, level+1, result);
        traversal(root->right,level+1, result);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        traversal(root,0,result);
        for(int i=1;i<result.size();i+=2)
        {
            reverse(result[i].begin(),result[i].end());
        }
        return result;
    }
};