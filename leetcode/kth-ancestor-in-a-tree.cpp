/*
    name= kth ancestor in a tree
    link- https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(n)
    method 1;
*/


int ans;
bool findKthAncestor(Node *root, int node,int& k){
    if(!root) return false;
    
    if(root->data== node){
        k= k-1;
        return true;
    }
    
    bool flag1= findKthAncestor(root->left, node, k);
    if(flag1){
        if(k ==0){
            ans= root->data;
            return false;
        }
        k--;
        return true;
    }
    bool flag2= findKthAncestor(root->right, node, k);
    if(flag2){
        if(k==0){
            ans= root->data;
            return false;
        }
        k--;
        return true;
    }

}

int kthAncestor(Node *root, int k, int node)
{
    ans= -1;
    findKthAncestor(root,node, k);
    return ans;
}
