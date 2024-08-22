/*
    name= check if tree is isomorphic
    link- https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1
    author- Parth garg
    time complexity- o(min(m,n)) m,n are size of tree
    space complexity- o(min(m,n)) 
    method 1;
*/

class Solution{
  public:
    
    bool isIsomorphic(Node *root1,Node *root2)
    {
        if((!root1 && root2) || (!root2 && root1) ) return false;
        else if(!root1 && !root2) return true;
        
        if(root1->data != root2->data) return false;
        
        bool checkParallel= isIsomorphic(root1->left,root2->left) & isIsomorphic(root1->right, root2->right);
        bool checkCross= isIsomorphic(root1->left,root2->right) & isIsomorphic(root1->right, root2->left);
        
        return checkParallel || checkCross;
    }
};