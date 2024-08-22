/*
    name= brothers from different roots
    link- https://practice.geeksforgeeks.org/problems/brothers-from-different-root/1
    author- Parth garg
    time complexity- o(n1+n2) 
    space complexity- o(h1+h2)
    method 1;
*/

class Solution
{
public:
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        if(!root1 || !root2) return 0;
        int ans=0;
        stack<Node *> st1,st2;
        Node * top1;
        Node * top2;
        
        while(1){
            while(root1){
                st1.push(root1);
                root1= root1->left;
            }
            while(root2){
                st2.push(root2);
                root2= root2->right;
            }
            if(st1.empty() || st2.empty()) break;
            top1= st1.top();
            top2= st2.top();
            if((top1->data+ top2->data) == x){
                ans++;
                st1.pop();
                st2.pop();
                root1= top1->right;
                root2= top2->left;
            }
            else if((top1->data + top2->data) >x){
                st2.pop();
                root2= top2->left;
            }
            else{
                st1.pop();
                root1= top1->right;
            }
        }
        return ans;
    }
};