/*
    name= Longest ZigZag Path in a Binary Tree
    link- https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n) stack
    method 1;
*/
class Solution {
public:
    pair<int,int> findMax(TreeNode *root, int& ans){
        if(!root->left && !root->right){
            return {0,0};
        }
        else if(!root->left){
            pair<int,int> x= findMax(root->right,ans);
            ans= max(ans, x.first +1);
            return {0,x.first+1};
        }
        else if(!root->right){
            pair<int,int> x= findMax(root->left, ans);
            ans= max(ans, x.second+1);
            return {x.second+1,0};
        }
        else{
            pair<int,int> x= findMax(root->right,ans);
            pair<int,int> y= findMax(root->left, ans);
            ans= max(ans, x.first+1);
            ans= max(ans, y.second +1);
            return { y.second+1,x.first+1};
        }
    }

    int longestZigZag(TreeNode* root) {
        int ans= 0;
        pair<int,int> p= findMax(root, ans);
        return ans;
    }
};