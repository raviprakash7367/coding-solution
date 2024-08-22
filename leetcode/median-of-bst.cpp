/*
    name= median of bst
    link- https://practice.geeksforgeeks.org/problems/median-of-bst/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

int findCount(struct Node *root){
    if(!root) return 0;
    return 1+ findCount(root->left)+findCount(root->right);
}

void inorder(struct Node *root, int& val1, int& val2,int &mid){
    if(!root) return;
    inorder(root->left, val1,val2,mid);
    mid--;
    if(mid==0){
        val1= root->data;
    }
    else if(mid== -1){
        val2= root->data;
        return;
    }
    
    inorder(root->right,val1,val2,mid);
}

float findMedian(struct Node *root)
{
    
      int n= findCount(root);
      if(n==1) return root->data;
      int mid= (n+1)/2;
    //   cout<<n<<endl;
      int val1,val2;
      inorder(root, val1,val2,mid);
      if(n%2==1) return val1*(1.0);
      else return ((val1+val2)*(1.0))/2.0;
      
      
}
