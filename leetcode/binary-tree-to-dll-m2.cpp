/* 
    name= binary tree to DLL
    link- https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1
    author- Parth garg
    time complexity-o(n)
    space complexity- o(H)
    method 1;
*/

class Solution
{
    public: 
        Node * prev= NULL, *head= NULL;
    void inorderTraversal(Node* node){
        if(!node) return ;
        
        inorderTraversal(node->left);
        
        if(head == NULL){
            head= node;
        }
        else{
            node->left= prev;
            prev->right= node;
        }
        prev= node;
        inorderTraversal(node->right);
         
    }
    
    
    Node * bToDLL(Node *root)
    {
        inorderTraversal(root);
        return head;
    }
};