/*
    name= Construct Tree from Inorder & Preorder
    link- https://practice.geeksforgeeks.org/problems/construct-tree-1/1
    author- Parth garg
    time complexity- o(n*n)
    space complexity- o(n)
    method 1;
*/

class Solution{
    public:
    int x;
    Node* buildRecursively(int in[],int pre[],int n, int l, int r){
        if(l>r)return NULL;
        
        int pt= -1;
        for(int i=l;i<=r;i++){
            if(in[i]== pre[x]){
                pt= i; 
                break;
            }
        }
        
        Node * newNode= new Node(pre[x]);
        
        x++;
        if(pt!= -1){
            newNode->left= buildRecursively( in,pre,n,l,pt-1);
            newNode->right= buildRecursively(in,pre,n,pt+1,r);
        }
        return newNode;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        x=0;
        Node *head= buildRecursively(in,pre,n,0,n-1);
        return head;
    }
};