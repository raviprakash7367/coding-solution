/*
    name= construct bst from preorder traversal
    link-  https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
    author- Parth garg
    time complexity- o(n)
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
    TreeNode *createBst(vector<int>&nums, int*i, int min, int max, int key){
        if(*i >= nums.size()) return NULL;

        TreeNode* root= NULL;
        if(key>min && key <max){

            root= new TreeNode(key);
            *i = *i+1;

            if(*i < nums.size())root->left= createBst(nums,i,min,key,nums[*i]);
            if(*i < nums.size())root->right= createBst(nums,i,key,max,nums[*i]);
        }
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& nums) {
        
        int i=0;
        return createBst(nums,&i,INT_MIN,INT_MAX,nums[0]);
    }
};