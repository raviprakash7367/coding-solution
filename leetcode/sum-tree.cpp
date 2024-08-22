/*
    name= sum tree
    link- https://practice.geeksforgeeks.org/problems/sum-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h) height of tree
    method 1;
*/

class Solution
{
    public:
    bool ans;
    int sum(Node *root){
        if(!root) return 0;
        int ls= sum(root->left);
        int rs= sum(root->right);
        
        if((root->left!= NULL || root->right!= NULL) && root->data != ls+rs) ans= false;
        return ls+rs+ (root->data);
    }
    
    bool isSumTree(Node* root)
    {
        ans= true;
        sum(root);
        return ans;
    }
};