/*
    name= Flattening a Linked List
    link- https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
    author- Parth garg
    time complexity- o(m*n)
    space complexity- o(1)
    method 1;
*/




/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL)
    {
        return root;
    }
    
    Node *curr= root;
    Node *nxt= root->next;
    Node *currBtm= curr->bottom;
    
    while(curr->next != NULL )
    {
        while(curr->bottom!= NULL && nxt->data >= curr->bottom->data)
        {
            curr->bottom->next= nxt;
            curr->next= NULL;
            curr= curr->bottom;
        }
        currBtm= curr->bottom;
        curr->bottom= nxt;
        curr= curr->bottom;
        nxt= curr->next;
        
        Node *list= curr;
        Node *temp1= curr->bottom;
        Node *temp2= currBtm;
        
        // merge sort between temp1 and temp2 sub linked list 
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data > temp2->data)
            {
                list->bottom= temp2;
                temp2= temp2->bottom;
                list= list->bottom;
            }
            else 
            {
                list->bottom= temp1;
                temp1= temp1->bottom;
                list= list->bottom;
            }
        }
        if(temp1 != NULL) 
        {
            list->bottom = temp1;
            temp1= NULL;
        }
        if(temp2 != NULL)
        {
            list->bottom= temp2;
            temp2= NULL;
        }
    }
    
    return root;
    
}
