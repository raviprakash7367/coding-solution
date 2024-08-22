/*
    name= duplicate subtree in binary tree
    link- https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/
class Solution {
  public:
    
    unordered_map<string,int>m;
    string dfs(Node *root){
        if(!root) return "$";
        if(root->left == NULL && root->right == NULL) return "$"+to_string(root->data);
        
        string s= to_string(root->data) + dfs(root->left)+ dfs(root->right);
        m[s]++;
        return s;
    }
    
    int dupSub(Node *root) {
         if(!root) return 0;
         dfs(root);
         for(auto mp:m){
             if(mp.second >=2) return 1;
         }
         return 0;
    }
};