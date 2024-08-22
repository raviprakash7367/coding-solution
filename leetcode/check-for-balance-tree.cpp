/*
    name= check for balance tree
    link- https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/

class Solution{
    public:
    
    int diff(Node *node,bool &ans){
        if(!node) return 0;
        
        int lh= diff(node->left,ans);
        int rh= diff(node->right,ans);
        
        if(abs(lh-rh)>=2) ans= false;
        return 1+max(lh,rh);
    }
    bool isBalanced(Node *root)
    {
        bool ans= true;
        diff(root, ans);
        return ans;
    }
};