/*
    name= house robber-iii
    link-  https://leetcode.com/problems/house-robber-iii/
    author- Parth garg
    time complexity- o(n)
    method 1- make a map in which we will use address as key, 
    now the logic is that for every node we have 2 choices (i) if we select that node then
     we cannot select the just next level node and similarly for (ii) if we have not selected 
     that node then we will call the function for just next level nodes.
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
    unordered_map<TreeNode* , int> m;
    int recursion(TreeNode* root)
    {
        if(!root) return 0;
        if(m[root] != 0 ) return m[root];
        
        //when current node is included
        int ans1= root->val + ((root->left==NULL)? 0: recursion(root->left->left))+
            ((root->left== NULL)? 0: recursion(root->left->right))+
            ((root->right==NULL)? 0: recursion(root->right->left))+
            ((root->right==NULL)? 0: recursion(root->right->right));
        
        //when current node is not included
        int ans2= recursion(root->left)+ recursion(root->right);
        return m[root]= max(ans1,ans2);
        
    }
    int rob(TreeNode* root) {     
        return recursion(root);
    }
};