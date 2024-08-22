/*
    name= check for bst
    link- https://practice.geeksforgeeks.org/problems/check-for-bst/1
    author- Parth garg
    time complexity- o(n)
    space complexity- o(h)
    method 1;
*/

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        if(!root) return true;
        stack<Node *>st;
        
        int prev= INT_MIN;
        st.push(root);
        Node * temp= st.top()->left;
        
        while(temp!= NULL || !st.empty()){
            while(temp!= NULL){
                st.push(temp);
                temp= temp->left;
            }
            if(st.top()->data <= prev) return false;
            prev= st.top()->data;
            temp= st.top()->right;
            st.pop();
            
        }
        return true;
        
    }
};