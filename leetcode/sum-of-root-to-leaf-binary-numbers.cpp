/*
    name= sum of root to leaf binary numbers
    link- https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    vector<int>result;
    void Traverse(TreeNode *root, int sum)
    {
        if(!root) return ;
        sum= (sum*2)+ root->val;
        
        if(!root->left && !root->right)
        {
            result.push_back(sum);
            return;
        }   
        
        Traverse(root->left, sum);
        Traverse(root->right,sum);
        
        // sum= (sum-root->val)/2;   
    }
    
    int sumRootToLeaf(TreeNode* root) {
        Traverse(root,0);
        int ans=0;
        for(int i=0;i<result.size();i++)
            ans+= result[i];
        return ans;
    }
};