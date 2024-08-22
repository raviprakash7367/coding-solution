/* 
    name= binary tree to DLL
    link- https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
    author- Parth garg
    time complexity-o(n*n)
    space complexity- o(H)
    method 1;
*/

class Solution
{
    public: 
    
    void inorderTraversal(Node* node){
        if(node== NULL)return;
        
        inorderTraversal(node->left);
        inorderTraversal(node->right);
        
        Node*temp1= node->left;
        if(temp1){ 
            while(temp1->right != NULL) temp1= temp1->right;
            node->left= temp1;
        }
        Node *temp2= node->right;
        if(temp2){
            while(temp2->left != NULL) temp2= temp2->left;
            node->right= temp2;
        }
        if(node->left!= NULL) node->left->right= node;
        if(node->right!= NULL) node->right->left= node;
        
    }
    
    
    Node * bToDLL(Node *root)
    {
        if(root== NULL) return NULL;
        inorderTraversal(root);
        while(root->left != NULL) root= root->left;
         return root;
    }
};
