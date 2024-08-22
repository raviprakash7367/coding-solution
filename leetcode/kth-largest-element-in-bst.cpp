/*
    name= kth largest element in bst
    link-  https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution
{
    public:
    
    
    void inorder(Node *root, int &k,int &ans)
    {
        if(!root) return;
        
        inorder(root->right, k,ans);
        k--;
        if(k==0){
            ans= root->data;
            return;
        }
        inorder(root->left,k,ans);
        
    }
    int kthLargest(Node *root, int k)
    {
        if(!root) return 0;
        int ans;
        inorder(root,k,ans);
        return ans;
    }
};