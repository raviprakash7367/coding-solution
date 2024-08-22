/*
    name= populate inorder successor for all nodes
    link-  https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution
{
public:

    void fillTheNext(Node *root, Node **nxt){
        if(root){
            fillTheNext(root->right, nxt);
            root->next= *nxt;
            *nxt= root;
            fillTheNext(root->left, nxt);
        }
    }
    
    void populateNext(Node *root)
    {
        Node *nxt= NULL;
        fillTheNext(root, &nxt);
        
    }
};