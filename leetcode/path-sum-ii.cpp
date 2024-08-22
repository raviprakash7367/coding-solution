/*
    name= path sum ii
    link- https://leetcode.com/problems/path-sum-ii/
    author- Parth garg
    time complexity- o(n)
    method 1-make a vector for storing a path and a vector<vector<>> for storing multiple possible paths
             after leaving every element don't forgot to pop that element from the vector
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
    vector<vector<int>>result;
    
    void check(TreeNode* root, int target, int sum,vector<int>&path)
    {
        if(!root) return ;
        path.push_back(root->val);
        sum+= root->val;
        
        if(sum == target && !root->left && !root->right) 
        {
            result.push_back(path);
            path.pop_back();
            return ;   
        }
        
        check(root->left, target,sum,path);
        check(root->right,target,sum,path);
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        check(root,targetSum,0,path);
        return result;
    }
};