/*
    name= Predecessor and Successor
    link-https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(logn)
    method 1;
*/

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root) return;
    
    if(root->key == key){
        if(root->left != NULL){
            Node* tmp= root->left;
            while(tmp->right)tmp= tmp->right;
            pre= tmp;
        }
        if(root->right != NULL){
            Node* tmp= root->right;
            while(tmp->left) tmp= tmp->left;
            suc= tmp;
        }
        return;
    }
    
    if(root->key > key){
        suc= root;
        findPreSuc(root->left, pre,suc,key);
    }
    else{
        pre = root;
        findPreSuc(root->right, pre,suc,key);
    }
}