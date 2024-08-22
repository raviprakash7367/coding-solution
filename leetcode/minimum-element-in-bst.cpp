/* 
    name= minimum element in bst
    link- https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1
    author- Parth garg
    time complexity- o(logn)
    space complexity- o(logn)
    method 1;
*/

int minValue(Node* root) {
    if(!root) return -1;
    Node *temp= root;
    while(temp->left != NULL)temp= temp->left;
    return temp->data;
}
