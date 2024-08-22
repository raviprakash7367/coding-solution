/*
    name= kth smallest element in bst
    link-  https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution {
  public:
    
    void inorder(Node *root, int &k,int &ans)
    {
        if(!root) return;
        
        inorder(root->left, k,ans);
        k--;
        if(k==0){
            ans= root->data;
            return;
        }
        inorder(root->right,k,ans);
    }
    
    int KthSmallestElement(Node *root, int k) {
        if(!root) return 0;
        int ans=-1;
        inorder(root,k,ans);
        return ans;
    }
};