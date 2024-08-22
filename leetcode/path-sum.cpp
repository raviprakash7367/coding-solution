/*
    name= Path sum
    link- https://leetcode.com/problems/path-sum/
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
    bool ans;
    void check(TreeNode* root, int target, int sum)
    {
        if(!root)
            return ;
        
        sum+= root->val;
        
        if(sum == target && !root->left && !root->right)
        {
            ans= true;
            return ;
        }
        
        check(root->left, target,sum);
        if(ans== true) return ;
        check(root->right,target,sum);
        return;

    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        ans= false;
        check(root,targetSum,0);
        return ans;
        
    }
};