/*
    name= Count BST nodes that lie in a given range
    link- https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution{
public:
    void inorder(Node *root, int l, int h, int &ans){
        if(!root) return;
        inorder(root->left , l, h , ans);
        if(root->data >=l && root->data <=h)ans++;
        inorder(root->right,l,h,ans);
    }

    int getCount(Node *root, int l, int h)
    {
         int ans=0;
         inorder(root,l,h,ans);
         return ans;
    }
};
