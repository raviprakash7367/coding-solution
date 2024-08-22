/*
    name= Copy List with Random Pointer
    link- https://leetcode.com/problems/copy-list-with-random-pointer/
    author- Parth garg
    time complexity- o(n)
    space complexity- o(1)
    method 1;
*/



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head== NULL) return NULL;
        
        //step1- after every node in original list add a new node between two nodes of original list
        Node *temp= head;
        while(temp->next != NULL)
        {
            Node* newnode= new Node(temp->val);
            Node *nxt= temp->next;
            temp->next= newnode;
            newnode->next= nxt;
            temp= nxt;
        }
        Node *newnode= new Node(temp->val);
        temp->next= newnode;
        newnode->next= NULL;

        // step 2-  temp->next->random = temp->random->next;
        temp= head;
        while(temp != NULL)
        {
            if(temp->random== NULL) temp->next->random= NULL;
            else temp->next->random = temp->random->next; 
            
            temp= temp->next->next;
        }
        
        //step3- separate both the lists 
        temp= head->next;
        Node *head1= temp;
        Node *temp1= head;
        while(temp != NULL && temp->next!= NULL)
        {
            temp1->next= temp1->next->next;
            temp->next= temp->next->next;
  
            temp= temp->next;
            temp1= temp1->next;
    
        }
        temp1->next= NULL;
        
        return head1;
   
    }
};