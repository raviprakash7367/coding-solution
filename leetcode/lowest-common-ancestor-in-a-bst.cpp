/*
    name= lowest common ancestor in a bst
    link-  https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1
    author- Parth garg
    time complexity- o(h) //height of tree
    space complexity- o(h)
    method 1;
*/

Node* LCA(Node *root, int n1, int n2)
{
   
   if(!root) return NULL;
   if(root->data > n1 && root->data > n2){
       return LCA(root->left, n1,n2);
   }
   else if(root->data <n1 && root->data <n2){
       return LCA(root->right, n1,n2);
   }
   else return root;
}


