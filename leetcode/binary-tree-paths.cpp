/*
    name= Binary tree paths
    link- https://leetcode.com/problems/binary-tree-paths/
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
    vector<string>result;   
    void Traverse(TreeNode *root, string s)
    {
        if(!root) return ;
        s+= "->"+ to_string(root->val);
        
        if(!root->left && !root->right)
        {
            if(s[0]=='-') s.erase(0,2);
            result.push_back(s);
            return;
        }   
        
        Traverse(root->left, s);
        Traverse(root->right,s);
        
        for(int i= s.length()-1;i>=0;i--)
        {
            if(s[i]=='-')
            {
                s.erase(s.length()-1,1);
                break;
            }
            else
            {
                s.erase(s.length()-1,1);
            }
        } 
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        Traverse(root,s);
        return result;
    }
};